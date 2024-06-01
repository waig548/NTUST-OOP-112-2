// Will Replace by OJ, DO NOT EDIT!
#include <iostream>

#include "IXMLParser.h"
#include "TestUtils.hpp"
#include "XMLTokenizer.h"

const std::string Case2_XML() {
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

void __Case2__test_root_Elements_At_0(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_0(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_1(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_2(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_3(IElement*);
void __Case2__test_root_Elements_At_1(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_0(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_1(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_2(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_3(IElement*);
void __Case2__test_root_Elements_At_2(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_0(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_1(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_2(IElement*);
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_3(IElement*);

void Case2() {
    auto      parser = CreateParser();
    IElement* root   = parser->Parse(Case2_XML());
    delete parser;
    MustEquals(root->Name(), "root");
    MustNoNull(root->Attributes());
    MustEquals(root->Attributes()->Count(), 0);
    MustEquals(root->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements());
    MustEquals(root->Elements()->Count(), 3);
    MustEquals(root->Elements()->At(3), nullptr);
    MustEquals(root->Elements()->At(2147483647), nullptr);
    __Case2__test_root_Elements_At_0(root);
    __Case2__test_root_Elements_At_1(root);
    __Case2__test_root_Elements_At_2(root);
    delete root;
}
void __Case2__test_root_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(0)->Name(), "food");
    MustNoNull(root->Elements()->At(0)->Attributes());
    MustEquals(root->Elements()->At(0)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(0)->Elements());
    MustEquals(root->Elements()->At(0)->Elements()->Count(), 4);
    MustEquals(root->Elements()->At(0)->Elements()->At(4), nullptr);
    MustEquals(root->Elements()->At(0)->Elements()->At(2147483647), nullptr);
    __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_0(root);
    __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_1(root);
    __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_2(root);
    __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_3(root);
}
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Name(), "name");
    MustNoNull(root->Elements()->At(0)->Elements()->At(0)->Attributes());
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(0)->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Content()->AsString(), "Belgian Waffles");
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(0)->Elements()->At(0)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Name(), "price");
    MustNoNull(root->Elements()->At(0)->Elements()->At(1)->Attributes());
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(0)->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Content()->AsString(), "$5.95");
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(0)->Elements()->At(1)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Name(), "description");
    MustNoNull(root->Elements()->At(0)->Elements()->At(2)->Attributes());
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(0)->Elements()->At(2)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Content()->AsString(), "Two of our famous Belgian Waffles with plenty of real maple syrup");
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(0)->Elements()->At(2)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL0RR_Elements_At_3(IElement* root) {
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Name(), "calories");
    MustNoNull(root->Elements()->At(0)->Elements()->At(3)->Attributes());
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(0)->Elements()->At(3)->Content());
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Content()->AsString(), "650");
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Content()->IsInt(), true);
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Content()->AsInt(), 650);
    MustEquals(root->Elements()->At(0)->Elements()->At(3)->Content()->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(0)->Elements()->At(3)->Content()->AsDouble(), 650.0);
}
void __Case2__test_root_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(1)->Name(), "food");
    MustNoNull(root->Elements()->At(1)->Attributes());
    MustEquals(root->Elements()->At(1)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(1)->Elements());
    MustEquals(root->Elements()->At(1)->Elements()->Count(), 4);
    MustEquals(root->Elements()->At(1)->Elements()->At(4), nullptr);
    MustEquals(root->Elements()->At(1)->Elements()->At(2147483647), nullptr);
    __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_0(root);
    __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_1(root);
    __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_2(root);
    __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_3(root);
}
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Name(), "name");
    MustNoNull(root->Elements()->At(1)->Elements()->At(0)->Attributes());
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(1)->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Content()->AsString(), "Strawberry Belgian Waffles");
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(1)->Elements()->At(0)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Name(), "price");
    MustNoNull(root->Elements()->At(1)->Elements()->At(1)->Attributes());
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(1)->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Content()->AsString(), "$7.95");
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(1)->Elements()->At(1)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Name(), "description");
    MustNoNull(root->Elements()->At(1)->Elements()->At(2)->Attributes());
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(1)->Elements()->At(2)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Content()->AsString(), R"(Light Belgian waffles covered with strawberries and whipped cream)");
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(1)->Elements()->At(2)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL1RR_Elements_At_3(IElement* root) {
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Name(), "calories");
    MustNoNull(root->Elements()->At(1)->Elements()->At(3)->Attributes());
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(1)->Elements()->At(3)->Content());
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Content()->AsString(), "900");
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Content()->IsInt(), true);
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Content()->AsInt(), 900);
    MustEquals(root->Elements()->At(1)->Elements()->At(3)->Content()->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(1)->Elements()->At(3)->Content()->AsDouble(), 900.0);
}
void __Case2__test_root_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(2)->Name(), "food");
    MustNoNull(root->Elements()->At(2)->Attributes());
    MustEquals(root->Elements()->At(2)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(2)->Elements());
    MustEquals(root->Elements()->At(2)->Elements()->Count(), 4);
    MustEquals(root->Elements()->At(2)->Elements()->At(4), nullptr);
    MustEquals(root->Elements()->At(2)->Elements()->At(2147483647), nullptr);
    __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_0(root);
    __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_1(root);
    __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_2(root);
    __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_3(root);
}
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Name(), "name");
    MustNoNull(root->Elements()->At(2)->Elements()->At(0)->Attributes());
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(2)->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Content()->AsString(), "Berry-Berry Belgian Waffles");
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(2)->Elements()->At(0)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Name(), "price");
    MustNoNull(root->Elements()->At(2)->Elements()->At(1)->Attributes());
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(2)->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Content()->AsString(), "$8.95");
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(2)->Elements()->At(1)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Name(), "description");
    MustNoNull(root->Elements()->At(2)->Elements()->At(2)->Attributes());
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(2)->Elements()->At(2)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Content()->AsString(), R"(Belgian waffles covered with assorted fresh berries and whipped cream)");
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(2)->Elements()->At(2)->Content()->AsDouble(), 0.0);
}
void __Case2__test_root_ElementsLLRR_AtLL2RR_Elements_At_3(IElement* root) {
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Name(), "calories");
    MustNoNull(root->Elements()->At(2)->Elements()->At(3)->Attributes());
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Attributes()->Count(), 0);
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(2)->Elements()->At(3)->Content());
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Content()->AsString(), "900");
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Content()->IsInt(), true);
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Content()->AsInt(), 900);
    MustEquals(root->Elements()->At(2)->Elements()->At(3)->Content()->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(2)->Elements()->At(3)->Content()->AsDouble(), 900.0);
}