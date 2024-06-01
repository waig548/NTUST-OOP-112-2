/**
 * @brief
 * Please implement the specified classes within the function as
 * described in "IXMLParser.h".
 *
 * The name of classes doesn't matter.
 * But ensure the class that implements IXMLParser, can be constructed in CreateParser().
 */

#include "IXMLParser.h"
#include "XMLTokenizer.h"

#include <regex>
#include <queue>
#include <stack>

class Value : public IValue
{
public:
	Value(const std::string &rawValue) : rawValue(rawValue)
	{
	}

	Value(const Value &other) : Value(other.rawValue)
	{
	}

	~Value()
	{
	}

	std::string AsString() const
	{
		return rawValue;
	}

	bool IsInt() const
	{
		return std::regex_match(rawValue, IntPattern);
	}

	int AsInt() const
	{
		if (!IsInt())
			return 0;
		return std::stoi(rawValue);
	}

	bool IsDouble() const
	{
		return std::regex_match(rawValue, DoublePattern);
	}

	double AsDouble() const
	{
		if (!IsDouble())
			return 0;
		return std::stod(rawValue);
	}

protected:
	std::string rawValue;

	static const std::regex IntPattern;
	static const std::regex DoublePattern;
};

const std::regex Value::IntPattern = std::regex("^[+-]{0,1}[0-9]+$");
const std::regex Value::DoublePattern = std::regex("^[+-]{0,1}(([0-9]+[.]{0,1}[0-9]*)|([0-9]*[.]{0,1}[0-9]+))$");

class Attribute : public Value
{
public:
	Attribute(const std::string &key, const Value &value) : name(key), Value(value)
	{
	}

	Attribute(const std::string &key, const std::string &rawValue) : Attribute(key, Value(rawValue))
	{
	}

	Attribute(const Attribute &other) : Attribute(other.name, other.rawValue)
	{
	}

	~Attribute()
	{
	}

	std::string Name() const
	{
		return name;
	}

private:
	std::string name;

	static const std::regex KeyPattern;
};

const std::regex KeyPattern = std::regex("^[A-Za-z0-9-]+$");

class AttributeList : public IAttributeEnumerable
{
public:
	size_t Count() const
	{
		return attributes.size();
	}

	IValue *Get(const std::string &name) const
	{
		auto it = std::find_if(attributes.begin(), attributes.end(), [name](Attribute *attr)
							   { return attr->Name() == name; });
		if (it != attributes.end())
			return *it;
		return nullptr;
	}

	void push_back(Attribute *attr)
	{
		attributes.push_back(attr);
	}

private:
	std::vector<Attribute *> attributes;
};

class ElementList : public IElementEnumerable
{
public:
	size_t Count() const
	{
		return elements.size();
	}
	IElement *At(size_t index) const
	{
		if (index >= elements.size())
			return nullptr;
		return elements[index];
	}

	IElementEnumerable *Filter(const std::string &name) const
	{
		auto res = new ElementList();
		for (auto e : elements)
			if (e->Name() == name)
				res->push_back(e);
		return res;
	}

	void push_back(IElement *newElement)
	{
		elements.push_back(newElement);
	}

private:
	std::vector<IElement *> elements;
};

class Element : public IElement
{
public:
	Element(const std::string &name, IAttributeEnumerable *attributes, IElementEnumerable *elements, IValue *content) : name(name), attributes(attributes), elements(elements), content(content)
	{
	}

	const std::string &Name() const
	{
		return name;
	}

	IAttributeEnumerable *Attributes() const
	{
		return attributes;
	}

	IElementEnumerable *Elements() const
	{
		return elements;
	}

	IValue *Content() const
	{
		return content;
	}

private:
	std::string name;
	IAttributeEnumerable *attributes;
	IElementEnumerable *elements;
	IValue *content;
};

class XMLParser : public IXMLParser
{
private:
	std::vector<XMLTokenizer::Token *> tokenQueue;
	size_t pos = 0;

	bool nextString(std::string &out)
	{
		if (pos >= tokenQueue.size())
			return false;
		if (tokenQueue[pos]->Type() != XMLTokenizer::TokenType::STR)
			return false;
		out = tokenQueue[pos]->Cast<XMLTokenizer::StringToken>()->Value();
		pos++;
		return true;
	}

	bool beginTag(bool endElement = false)
	{
		if (pos >= tokenQueue.size())
			return false;
		if (endElement && tokenQueue[pos]->Type() != XMLTokenizer::TokenType::LT_END)
			return false;
		if (!endElement && tokenQueue[pos]->Type() != XMLTokenizer::TokenType::LT)
			return false;
		pos++;
		return true;
	}

	bool endTag()
	{
		if (pos >= tokenQueue.size())
			return false;
		if (tokenQueue[pos]->Type() != XMLTokenizer::TokenType::GT)
			return false;
		pos++;
		return true;
	}

	bool beginElement()
	{
		return beginTag();
	}

	bool shouldEndElement()
	{
		return tokenQueue[pos]->Type() == XMLTokenizer::TokenType::LT_END;
	}

	bool endElement()
	{
		return beginTag(true);
	}

	bool beginAttribute(std::string &key)
	{
		return nextString(key);
	}

	bool consumeEqual()
	{
		if (pos >= tokenQueue.size())
			return false;
		if (tokenQueue[pos]->Type() != XMLTokenizer::TokenType::EQUAL)
			return false;
		pos++;
		return true;
	}

	bool endAttribute(std::string &value)
	{
		if (!nextString(value))
			return false;
		value = value.substr(1, value.size() - 2);
		return true;
	}

	Attribute *parseAttribute()
	{
		bool flag = true;
		std::string key, value;
		flag = beginAttribute(key);
		flag = consumeEqual();
		flag = endAttribute(value);
		if (!flag)
			throw std::exception("Error parsing Attribute");
		return new Attribute(key, value);
	}

	IElement *parseElement()
	{
		std::string name;
		AttributeList *attrs = new AttributeList();
		ElementList *elems = new ElementList();
		std::string content;
		if (!beginElement())
			throw std::exception("Token should be \"<\"");
		if (!nextString(name))
			throw std::exception("Token should be a string");
		while (!endTag())
		{
			attrs->push_back(parseAttribute());
		}
		if (!nextString(content))
		{
			while (!shouldEndElement())
			{
				elems->push_back(parseElement());
			}
		}
		if (!endElement())
			throw std::exception("Token should be \"</\"");
		std::string endName;
		if (!(nextString(endName) && endName == name))
			throw std::exception("Element name not match");
		if (!endTag())
			throw std::exception("Element end tag not finished");
		if (elems->Count())
			return new Element(name, attrs, elems, nullptr);
		else
			return new Element(name, attrs, elems, new Value(content));
	}

public:
	IElement *Parse(const std::string &rawXML)
	{
		tokenQueue = XMLTokenizer::Tokenize(rawXML);
		pos = 0;

		try
		{
			return parseElement();
		}
		catch (const std::exception &e)
		{
			tokenQueue.clear();
			return nullptr;
			// throw std::exception((std::string(e.what()) + " at position: " + std::to_string(pos)).c_str());
		}
	}
};

IXMLParser *CreateParser()
{
	return new XMLParser();
}