// Will Replace by OJ, DO NOT EDIT!
#include <iostream>

#include "IXMLParser.h"
#include "TestUtils.hpp"
#include "XMLTokenizer.h"

const std::string Case3_XML() {
    std::string xml = R"IMAXMLNOTHTML(
<rootabyss maintainer="damien">
    <food name="Belgian Waffles" price="$5.95" calories="650" description="Two of our famous Belgian Waffles with plenty of real maple syrup"></food>
    <food name="Strawberry Belgian Waffles" price="$7.95" calories="900.9999" description="Light Belgian waffles covered with strawberries and whipped cream">
    </food>
    <lunhuibeishi price="NT$40000" description="A very expensive stone" > </lunhuibeishi>
    <food name="Berry-Berry Belgian Waffles" price = "$8.95" calories= "900.0" description ="Belgian waffles covered with assorted fresh berries and whipped cream">
        Not health food!
        Good Good Eat!
    </food>
    <food name="dirt" price = "$0.00" risk="+100" calories= "0." rating="-1." description ="Emergency food">
        <grass-1 name="kusa" calories="+.5" rating="+1">Cannot eat</grass-1>
        <grass-2 name="kusakusa" calories="-.50" rating="-2">Cannot eat</grass-2>
    </food>
</rootabyss>
)IMAXMLNOTHTML";

    // std::cout << "===TOKENS===" << std::endl;
    // for (const auto& token: XMLTokenizer::Tokenize(xml)) {
    //     std::cout << token->ToString() << std::endl;
    //     delete token;
    // }
    // std::cout << "===TOKENS===" << std::endl;

    return xml;
}

void __Case3__test_root_Elements_At_0(IElement*);
void __Case3__test_root_Elements_At_1(IElement*);
void __Case3__test_root_Elements_At_2(IElement*);
void __Case3__test_root_Elements_At_3(IElement*);
void __Case3__test_root_Elements_At_4(IElement*);
void __Case3__test_root_ElementsLLRR_AtLL4RR_Elements_At_0(IElement*);
void __Case3__test_root_ElementsLLRR_AtLL4RR_Elements_At_1(IElement*);

void Case3() {
    auto      parser = CreateParser();
    IElement* root   = parser->Parse(Case3_XML());
    delete parser;
    MustEquals(root->Name(), "rootabyss");
    MustNoNull(root->Attributes());
    MustEquals(root->Attributes()->Count(), 1);
    MustEquals(root->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Attributes()->Get("maintainer"));
    MustEquals(root->Attributes()->Get("maintainer")->AsString(), "damien");
    MustEquals(root->Attributes()->Get("maintainer")->IsInt(), false);
    MustEquals(root->Attributes()->Get("maintainer")->AsInt(), 0);
    MustEquals(root->Attributes()->Get("maintainer")->IsDouble(), false);
    MustEquals(root->Attributes()->Get("maintainer")->AsDouble(), 0.0);
    MustNoNull(root->Elements());
    MustEquals(root->Elements()->Count(), 5);
    MustEquals(root->Elements()->At(5), nullptr);
    MustEquals(root->Elements()->At(2147483647), nullptr);
    __Case3__test_root_Elements_At_0(root);
    __Case3__test_root_Elements_At_1(root);
    __Case3__test_root_Elements_At_2(root);
    __Case3__test_root_Elements_At_3(root);
    __Case3__test_root_Elements_At_4(root);
    delete root;
}
void __Case3__test_root_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(0)->Name(), "food");
    MustNoNull(root->Elements()->At(0)->Attributes());
    MustEquals(root->Elements()->At(0)->Attributes()->Count(), 4);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(0)->Attributes()->Get("name"));
    MustEquals(root->Elements()->At(0)->Attributes()->Get("name")->AsString(), "Belgian Waffles");
    MustEquals(root->Elements()->At(0)->Attributes()->Get("name")->IsInt(), false);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("name")->AsInt(), 0);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("name")->IsDouble(), false);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("name")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(0)->Attributes()->Get("price"));
    MustEquals(root->Elements()->At(0)->Attributes()->Get("price")->AsString(), "$5.95");
    MustEquals(root->Elements()->At(0)->Attributes()->Get("price")->IsInt(), false);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("price")->AsInt(), 0);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("price")->IsDouble(), false);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("price")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(0)->Attributes()->Get("calories"));
    MustEquals(root->Elements()->At(0)->Attributes()->Get("calories")->AsString(), "650");
    MustEquals(root->Elements()->At(0)->Attributes()->Get("calories")->IsInt(), true);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("calories")->AsInt(), 650);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("calories")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(0)->Attributes()->Get("calories")->AsDouble(), 650.0);
    MustNoNull(root->Elements()->At(0)->Attributes()->Get("description"));
    MustEquals(root->Elements()->At(0)->Attributes()->Get("description")->AsString(), "Two of our famous Belgian Waffles with plenty of real maple syrup");
    MustEquals(root->Elements()->At(0)->Attributes()->Get("description")->IsInt(), false);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("description")->AsInt(), 0);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("description")->IsDouble(), false);
    MustEquals(root->Elements()->At(0)->Attributes()->Get("description")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(0)->Elements());
    MustEquals(root->Elements()->At(0)->Elements()->Count(), 0);
    MustNoNull(root->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(0)->Content()->AsString(), "");
    MustEquals(root->Elements()->At(0)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(0)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(0)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(0)->Content()->AsDouble(), 0.0);
}
void __Case3__test_root_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(1)->Name(), "food");
    MustNoNull(root->Elements()->At(1)->Attributes());
    MustEquals(root->Elements()->At(1)->Attributes()->Count(), 4);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(1)->Attributes()->Get("name"));
    MustEquals(root->Elements()->At(1)->Attributes()->Get("name")->AsString(), "Strawberry Belgian Waffles");
    MustEquals(root->Elements()->At(1)->Attributes()->Get("name")->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("name")->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("name")->IsDouble(), false);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("name")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(1)->Attributes()->Get("price"));
    MustEquals(root->Elements()->At(1)->Attributes()->Get("price")->AsString(), "$7.95");
    MustEquals(root->Elements()->At(1)->Attributes()->Get("price")->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("price")->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("price")->IsDouble(), false);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("price")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(1)->Attributes()->Get("calories"));
    MustEquals(root->Elements()->At(1)->Attributes()->Get("calories")->AsString(), "900.9999");
    MustEquals(root->Elements()->At(1)->Attributes()->Get("calories")->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("calories")->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("calories")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(1)->Attributes()->Get("calories")->AsDouble(), 900.9999);
    MustNoNull(root->Elements()->At(1)->Attributes()->Get("description"));
    MustEquals(root->Elements()->At(1)->Attributes()->Get("description")->AsString(), "Light Belgian waffles covered with strawberries and whipped cream");
    MustEquals(root->Elements()->At(1)->Attributes()->Get("description")->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("description")->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("description")->IsDouble(), false);
    MustEquals(root->Elements()->At(1)->Attributes()->Get("description")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(1)->Elements());
    MustEquals(root->Elements()->At(1)->Elements()->Count(), 0);
    MustNoNull(root->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(1)->Content()->AsString(), "");
    MustEquals(root->Elements()->At(1)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(1)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(1)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(1)->Content()->AsDouble(), 0.0);
}
void __Case3__test_root_Elements_At_2(IElement* root) {
    MustEquals(root->Elements()->At(2)->Name(), "lunhuibeishi");
    MustNoNull(root->Elements()->At(2)->Attributes());
    MustEquals(root->Elements()->At(2)->Attributes()->Count(), 2);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(2)->Attributes()->Get("price"));
    MustEquals(root->Elements()->At(2)->Attributes()->Get("price")->AsString(), "NT$40000");
    MustEquals(root->Elements()->At(2)->Attributes()->Get("price")->IsInt(), false);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("price")->AsInt(), 0);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("price")->IsDouble(), false);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("price")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(2)->Attributes()->Get("description"));
    MustEquals(root->Elements()->At(2)->Attributes()->Get("description")->AsString(), "A very expensive stone");
    MustEquals(root->Elements()->At(2)->Attributes()->Get("description")->IsInt(), false);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("description")->AsInt(), 0);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("description")->IsDouble(), false);
    MustEquals(root->Elements()->At(2)->Attributes()->Get("description")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(2)->Elements());
    MustEquals(root->Elements()->At(2)->Elements()->Count(), 0);
    MustNoNull(root->Elements()->At(2)->Content());
    MustEquals(root->Elements()->At(2)->Content()->AsString(), "");
    MustEquals(root->Elements()->At(2)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(2)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(2)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(2)->Content()->AsDouble(), 0.0);
}
void __Case3__test_root_Elements_At_3(IElement* root) {
    MustEquals(root->Elements()->At(3)->Name(), "food");
    MustNoNull(root->Elements()->At(3)->Attributes());
    MustEquals(root->Elements()->At(3)->Attributes()->Count(), 4);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(3)->Attributes()->Get("name"));
    MustEquals(root->Elements()->At(3)->Attributes()->Get("name")->AsString(), "Berry-Berry Belgian Waffles");
    MustEquals(root->Elements()->At(3)->Attributes()->Get("name")->IsInt(), false);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("name")->AsInt(), 0);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("name")->IsDouble(), false);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("name")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(3)->Attributes()->Get("price"));
    MustEquals(root->Elements()->At(3)->Attributes()->Get("price")->AsString(), "$8.95");
    MustEquals(root->Elements()->At(3)->Attributes()->Get("price")->IsInt(), false);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("price")->AsInt(), 0);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("price")->IsDouble(), false);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("price")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(3)->Attributes()->Get("calories"));
    MustEquals(root->Elements()->At(3)->Attributes()->Get("calories")->AsString(), "900.0");
    MustEquals(root->Elements()->At(3)->Attributes()->Get("calories")->IsInt(), false);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("calories")->AsInt(), 0);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("calories")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(3)->Attributes()->Get("calories")->AsDouble(), 900.0);
    MustNoNull(root->Elements()->At(3)->Attributes()->Get("description"));
    MustEquals(root->Elements()->At(3)->Attributes()->Get("description")->AsString(), "Belgian waffles covered with assorted fresh berries and whipped cream");
    MustEquals(root->Elements()->At(3)->Attributes()->Get("description")->IsInt(), false);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("description")->AsInt(), 0);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("description")->IsDouble(), false);
    MustEquals(root->Elements()->At(3)->Attributes()->Get("description")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(3)->Content());
    MustEquals(root->Elements()->At(3)->Content()->AsString(), R"(Not health food!
        Good Good Eat!)");
    MustEquals(root->Elements()->At(3)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(3)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(3)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(3)->Content()->AsDouble(), 0.0);
}
void __Case3__test_root_Elements_At_4(IElement* root) {
    MustEquals(root->Elements()->At(4)->Name(), "food");
    MustNoNull(root->Elements()->At(4)->Attributes());
    MustEquals(root->Elements()->At(4)->Attributes()->Count(), 6);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(4)->Attributes()->Get("name"));
    MustEquals(root->Elements()->At(4)->Attributes()->Get("name")->AsString(), "dirt");
    MustEquals(root->Elements()->At(4)->Attributes()->Get("name")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("name")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("name")->IsDouble(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("name")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(4)->Attributes()->Get("price"));
    MustEquals(root->Elements()->At(4)->Attributes()->Get("price")->AsString(), "$0.00");
    MustEquals(root->Elements()->At(4)->Attributes()->Get("price")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("price")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("price")->IsDouble(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("price")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(4)->Attributes()->Get("risk"));
    MustEquals(root->Elements()->At(4)->Attributes()->Get("risk")->AsString(), "+100");
    MustEquals(root->Elements()->At(4)->Attributes()->Get("risk")->IsInt(), true);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("risk")->AsInt(), +100);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("risk")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(4)->Attributes()->Get("risk")->AsDouble(), +100.0);
    MustNoNull(root->Elements()->At(4)->Attributes()->Get("calories"));
    MustEquals(root->Elements()->At(4)->Attributes()->Get("calories")->AsString(), "0.");
    MustEquals(root->Elements()->At(4)->Attributes()->Get("calories")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("calories")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("calories")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(4)->Attributes()->Get("calories")->AsDouble(), 0.);
    MustNoNull(root->Elements()->At(4)->Attributes()->Get("rating"));
    MustEquals(root->Elements()->At(4)->Attributes()->Get("rating")->AsString(), "-1.");
    MustEquals(root->Elements()->At(4)->Attributes()->Get("rating")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("rating")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("rating")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(4)->Attributes()->Get("rating")->AsDouble(), -1.);
    MustNoNull(root->Elements()->At(4)->Attributes()->Get("description"));
    MustEquals(root->Elements()->At(4)->Attributes()->Get("description")->AsString(), "Emergency food");
    MustEquals(root->Elements()->At(4)->Attributes()->Get("description")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("description")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("description")->IsDouble(), false);
    MustEquals(root->Elements()->At(4)->Attributes()->Get("description")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(4)->Elements());
    MustEquals(root->Elements()->At(4)->Elements()->Count(), 2);
    MustEquals(root->Elements()->At(4)->Elements()->At(2), nullptr);
    MustEquals(root->Elements()->At(4)->Elements()->At(2147483647), nullptr);
    __Case3__test_root_ElementsLLRR_AtLL4RR_Elements_At_0(root);
    __Case3__test_root_ElementsLLRR_AtLL4RR_Elements_At_1(root);
}
void __Case3__test_root_ElementsLLRR_AtLL4RR_Elements_At_0(IElement* root) {
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Name(), "grass-1");
    MustNoNull(root->Elements()->At(4)->Elements()->At(0)->Attributes());
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Count(), 3);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("name"));
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("name")->AsString(), "kusa");
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("name")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("name")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("name")->IsDouble(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("name")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("calories"));
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("calories")->AsString(), "+.5");
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("calories")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("calories")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("calories")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("calories")->AsDouble(), +.5);
    MustNoNull(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("rating"));
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("rating")->AsString(), "+1");
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("rating")->IsInt(), true);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("rating")->AsInt(), +1);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("rating")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(4)->Elements()->At(0)->Attributes()->Get("rating")->AsDouble(), +1.0);
    MustNoNull(root->Elements()->At(4)->Elements()->At(0)->Content());
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Content()->AsString(), "Cannot eat");
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(0)->Content()->AsDouble(), 0.0);
}
void __Case3__test_root_ElementsLLRR_AtLL4RR_Elements_At_1(IElement* root) {
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Name(), "grass-2");
    MustNoNull(root->Elements()->At(4)->Elements()->At(1)->Attributes());
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Count(), 3);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("NotExists"), nullptr);
    MustNoNull(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("name"));
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("name")->AsString(), "kusakusa");
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("name")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("name")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("name")->IsDouble(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("name")->AsDouble(), 0.0);
    MustNoNull(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("calories"));
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("calories")->AsString(), "-.50");
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("calories")->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("calories")->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("calories")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("calories")->AsDouble(), -.50);
    MustNoNull(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("rating"));
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("rating")->AsString(), "-2");
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("rating")->IsInt(), true);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("rating")->AsInt(), -2);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("rating")->IsDouble(), true);
    MustEquals_Double(root->Elements()->At(4)->Elements()->At(1)->Attributes()->Get("rating")->AsDouble(), -2.0);
    MustNoNull(root->Elements()->At(4)->Elements()->At(1)->Content());
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Content()->AsString(), "Cannot eat");
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Content()->IsInt(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Content()->AsInt(), 0);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Content()->IsDouble(), false);
    MustEquals(root->Elements()->At(4)->Elements()->At(1)->Content()->AsDouble(), 0.0);
}