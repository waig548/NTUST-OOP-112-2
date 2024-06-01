// Will Replace by OJ, DO NOT EDIT!
#ifndef IXMLParser_H
#define IXMLParser_H

#include <string>

class IXMLParser;
class IAttributeEnumerable;
class IElement;
class IElementEnumerable;
class IValue;

IXMLParser* CreateParser();

class IXMLParser {
    public:
    virtual ~IXMLParser() = default;
    // Parses the given XML string and returns the root element
    // A XML will always have and only have one root element
    virtual IElement* Parse(const std::string&) = 0;
};

class IElement {
    public:
    virtual ~IElement() = default;
    // Returns the element name
    virtual const std::string& Name() const = 0;

    // Returns the value of the attributes, should always return a not-null pointer, if no any attributes exists, Attributes()->Count() == 0
    virtual IAttributeEnumerable* Attributes() const = 0;

    // Returns all children elements, should always return a not-null pointer, if no any child element exists, Elements()->Count() == 0
    virtual IElementEnumerable* Elements() const = 0;

    // Returns text content as an IValue if and only if no child element exists, otherwise return a nullptr.
    // Ignoring leading and trailing whitespace` `, tabs`\t`, and newlines`\r`, `\n`, `\r\n`,
    virtual IValue* Content() const = 0;
};

class IAttributeEnumerable {
    public:
    virtual ~IAttributeEnumerable() = default;
    // Returns the count of attributes
    virtual size_t Count() const = 0;

    // Returns the attribute value as an IValue with the given name exactly the same, if the attribute does not exist, return nullptr
    virtual IValue* Get(const std::string& name) const = 0;
};

class IElementEnumerable {
    public:
    virtual ~IElementEnumerable() = default;
    // Returns the count of elements
    virtual size_t Count() const = 0;
    // Returns the element at the given index, if the index is out of range, return nullptr
    virtual IElement* At(size_t index) const = 0;

    // Filters the elements with the given name exactly the same
    virtual IElementEnumerable* Filter(const std::string& name) const = 0;
};

class IValue {
    public:
    virtual ~IValue() = default;

    // Returns the value as a std::string
    virtual std::string AsString() const = 0;

    // Returns true only if value is represented as an integer
    // e.g.:
    // "123",   "+123",   "-123"   => true
    // "123.4", "+123.4", "-123.4" => false
    // "123.0", "+123.0", "-123.0" => false
    // ".123",  "+.123",  "-.123"  => false
    // "123.",  "+123.",  "-123."  => false
    // ""       => false
    // "a"      => false
    // "1a"     => false
    // "1     " => false
    virtual bool IsInt() const = 0;
    // If the value not represented as an integer, return 0
    virtual int AsInt() const = 0;

    // Returns true only if value is represented as a number
    // e.g.:
    // "123",   "+123",   "-123"   => true
    // "123.4", "+123.4", "-123.4" => true
    // "123.0", "+123.0", "-123.0" => true
    // ".123",  "+.123",  "-.123"  => true
    // "123.",  "+123.",  "-123."  => true
    // ""       => false
    // "a"      => false
    // "1a"     => false
    // "1     " => false
    virtual bool IsDouble() const = 0;
    // If the value not represented as a number, return 0.0
    virtual double AsDouble() const = 0;
};

#endif  // IXMLParser_H