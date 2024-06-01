// Will Replace by OJ, DO NOT EDIT!
#include <iostream>

#include "IXMLParser.h"
#include "TestUtils.hpp"
#include "XMLTokenizer.h"

const std::string Case1_XML() {
    std::string xml = R"IMAXMLNOTHTML(
<root>
    <food>
        <name>Belgian Waffles</name>
        <price>$5.95</price>
        <description>Two of our famous Belgian Waffles with plenty of real maple syrup</description>
        <calories>650</calories>
    </food>
    <food>
        <name>Strawberry Belgian Waffles</name>
        <price>$7.95</price>
        <description>
            Light Belgian waffles covered with strawberries and whipped cream
        </description>
        <calories>900</calories>
    </food>
    <food>
        <name>Berry-Berry Belgian Waffles</name>
        <price>$8.95</price>
        <description>
            Belgian waffles covered with assorted fresh berries and whipped cream
        </description>
        <calories>900</calories>
    </food>
</root>
)IMAXMLNOTHTML";

    // std::cout << "===TOKENS===" << std::endl;
    // for (const auto& token: XMLTokenizer::Tokenize(xml)) {
    //     std::cout << token->ToString() << std::endl;
    //     delete token;
    // }
    // std::cout << "===TOKENS===" << std::endl;

    return xml;
}

void __Case1__test_root_Elements_At_0(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
void __Case1__test_root_Elements_At_1(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_2(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_3(IElement*);
void __Case1__test_root_Elements_At_2(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_0(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_1(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_2(IElement*);
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_3(IElement*);

void Case1() {
    auto      parser = CreateParser();
    IElement* root   = parser->Parse(Case1_XML());
    delete parser;
    MustEquals(root->Name(), "root");
    MustNoNull(root->Elements());
    MustEquals(root->Elements()->Count(), 3);
    MustEquals(root->Elements()->At(3), nullptr);
    MustEquals(root->Elements()->At(2147483647), nullptr);
    __Case1__test_root_Elements_At_0(root);
    __Case1__test_root_Elements_At_1(root);
    __Case1__test_root_Elements_At_2(root);
    delete root;
}
void __Case1__test_root_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(0)->Name(), "food");
    MustNoNull(root->Elements()->At(0)->Elements());
    MustEquals(root->Elements()->At(0)->Elements()->Count(), 4);
    MustEquals(root->Elements()->At(0)->Elements()->At(4), nullptr);
    MustEquals(root->Elements()->At(0)->Elements()->At(2147483647), nullptr);
    __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_0(root);
    __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_1(root);
    __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_2(root);
    __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_3(root);
}
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Name(), "name");
    MustNoNull(root->Elements()->At(0)->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Content()->AsString(), "Belgian Waffles");
}
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Name(), "price");
    MustNoNull(root->Elements()->At(0)->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Content()->AsString(), "$5.95");
}
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Name(), "description");
    MustNoNull(root->Elements()->At(0)->Elements()->At(2)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Content()->AsString(), "Two of our famous Belgian Waffles with plenty of real maple syrup");
}
void __Case1__test_root_ElementsLLRR_AtLL0RR_Elements_At_3(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Name(), "calories");
    MustNoNull(root->Elements()->At(0)->Elements()->At(3)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Content()->AsString(), "650");
}
void __Case1__test_root_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(1)->Name(), "food");
    MustNoNull(root->Elements()->At(1)->Elements());
    MustEquals(root->Elements()->At(1)->Elements()->Count(), 4);
    MustEquals(root->Elements()->At(1)->Elements()->At(4), nullptr);
    MustEquals(root->Elements()->At(1)->Elements()->At(2147483647), nullptr);
    __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_0(root);
    __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_1(root);
    __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_2(root);
    __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_3(root);
}
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Name(), "name");
    MustNoNull(root->Elements()->At(1)->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Content()->AsString(), "Strawberry Belgian Waffles");
}
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Name(), "price");
    MustNoNull(root->Elements()->At(1)->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Content()->AsString(), "$7.95");
}
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Name(), "description");
    MustNoNull(root->Elements()->At(1)->Elements()->At(2)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Content()->AsString(), R"(Light Belgian waffles covered with strawberries and whipped cream)");
}
void __Case1__test_root_ElementsLLRR_AtLL1RR_Elements_At_3(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Name(), "calories");
    MustNoNull(root->Elements()->At(1)->Elements()->At(3)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Content()->AsString(), "900");
}
void __Case1__test_root_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(2)->Name(), "food");
    MustNoNull(root->Elements()->At(2)->Elements());
    MustEquals(root->Elements()->At(2)->Elements()->Count(), 4);
    MustEquals(root->Elements()->At(2)->Elements()->At(4), nullptr);
    MustEquals(root->Elements()->At(2)->Elements()->At(2147483647), nullptr);
    __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_0(root);
    __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_1(root);
    __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_2(root);
    __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_3(root);
}
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Name(), "name");
    MustNoNull(root->Elements()->At(2)->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Content()->AsString(), "Berry-Berry Belgian Waffles");
}
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Name(), "price");
    MustNoNull(root->Elements()->At(2)->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Content()->AsString(), "$8.95");
}
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Name(), "description");
    MustNoNull(root->Elements()->At(2)->Elements()->At(2)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Content()->AsString(), R"(Belgian waffles covered with assorted fresh berries and whipped cream)");
}
void __Case1__test_root_ElementsLLRR_AtLL2RR_Elements_At_3(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Name(), "calories");
    MustNoNull(root->Elements()->At(2)->Elements()->At(3)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Content()->AsString(), "900");
}