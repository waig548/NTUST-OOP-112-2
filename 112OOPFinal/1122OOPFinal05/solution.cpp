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

class Value: public IValue {};

class Attribute: public Value {};

class AttributeList: public IAttributeEnumerable {};

class ElementList: public IElementEnumerable {};

class Element: public IElement {};

class XMLParser: public IXMLParser {};

IXMLParser* CreateParser() {
    return new XMLParser();
}