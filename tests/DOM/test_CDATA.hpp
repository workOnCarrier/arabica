#ifndef ARABICA_TEST_SAX2DOM_CDATA_HPP
#define ARABICA_TEST_SAX2DOM_CDATA_HPP

#include "../CppUnit/framework/TestCase.h"
#include "../CppUnit/framework/TestSuite.h"
#include "../CppUnit/framework/TestCaller.h"

#include <DOM/Simple/DOMImplementation.h>

template<class string_type, class string_adaptor>
class CDATATest : public TestCase 
{
  DOM::DOMImplementation<string_type> factory;
  typedef string_adaptor SA;

  public: 
    CDATATest(std::string name) :
        TestCase(name) 
    {
    } // CDATATest
    
    void setUp() 
    {
      factory = SimpleDOM::DOMImplementation<string_type, string_adaptor>::getDOMImplementation();
    } // setUp

    void testNull() 
    {
      DOM::CDATASection<string_type> d;
      DOM::Node<string_type> n;
      assert(d == 0);
      assert(n == 0);
      assert(n == d);
    } // testNull

    void testCreate()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""),SA::construct_from_utf8(""), 0);
      DOM::CDATASection<string_type> t = d.createCDATASection(SA::construct_from_utf8("some data"));

      assert(t.getData() == SA::construct_from_utf8("some data"));
      assert(t.getNodeName() == SA::construct_from_utf8("#cdata-section"));
      assert(t.getNodeValue() == t.getData());

      t.setData(SA::construct_from_utf8("newData"));
      assert(t.getData() == SA::construct_from_utf8("newData"));
    } // testCreate

    void testConversion()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""),SA::construct_from_utf8(""), 0);
      DOM::CDATASection<string_type> t = d.createCDATASection(SA::construct_from_utf8("some data"));

      DOM::Node<string_type> n;

      assert(n != t);

      n = t;
      assert(n == t);

      DOM::CDATASection<string_type> t2;

      assert(n != t2);

      t2 = DOM::CDATASection<string_type>(n);
      assert(t == t2);
      assert(n == t2);

      DOM::CDATASection<string_type> t3;
      t3 = t2;
      assert(t3 == t2);
      assert(t3 == t);

      DOM::Comment<string_type> c = d.createComment(SA::construct_from_utf8("woo"));
      try {
        t = DOM::CDATASection<string_type>(c);
        assertImplementation(false, "converted comment to text");
      } 
      catch(const std::bad_cast&) {
      }
    } // testConverstion

    void testConversionToText()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""),SA::construct_from_utf8(""), 0);
      DOM::CDATASection<string_type> cd = d.createCDATASection(SA::construct_from_utf8("some data"));

      DOM::Text<string_type> t;
      assert(t == 0);
      assert(cd != t);
      t = cd;
      assert(cd == t);

      DOM::CDATASection<string_type> cd2;
      assert(cd2 == 0);
      cd2 = DOM::CDATASection<string_type>(t);
      assert(cd2 == t);
      assert(t == cd2);
      assert(cd == cd2);
      assert(cd2 == cd);

      t = d.createTextNode(SA::construct_from_utf8("boom"));
      try {
        cd = DOM::CDATASection<string_type>(t);
        assertImplementation(false, "converted text to CDATA");
      } 
      catch(const std::bad_cast&) {
      }
    } // testConversionToTest

    void testEverythingElse()
    {
      DOM::Document<string_type> d = factory.createDocument(SA::construct_from_utf8(""),SA::construct_from_utf8(""), 0);
      DOM::CDATASection<string_type> t = d.createCDATASection(SA::construct_from_utf8("some data"));

      assert(t.getNodeType() == DOM::Node<string_type>::CDATA_SECTION_NODE);
      assert(t.hasAttributes() == false);
      assert(t.getAttributes() == 0);
      assert(t.getChildNodes() == 0);
      assert(t.getFirstChild() == 0);

      try
      {
        t.appendChild(DOM::Node<string_type>());
      } 
      catch(const DOM::DOMException&)
      {
      } 

      assert(t.getFirstChild() == 0);

      assert(t.getOwnerDocument() == d);
      assert(t.getParentNode() == 0);
    } // 
};

template<class string_type, class string_adaptor>
TestSuite* CDATATest_suite() 
{
    TestSuite *suiteOfTests = new TestSuite;
    suiteOfTests->addTest(new TestCaller<CDATATest<string_type, string_adaptor> >("testNull", &CDATATest<string_type, string_adaptor> ::testNull));
    suiteOfTests->addTest(new TestCaller<CDATATest<string_type, string_adaptor> >("testCreate", &CDATATest<string_type, string_adaptor> ::testCreate));
    suiteOfTests->addTest(new TestCaller<CDATATest<string_type, string_adaptor> >("testConversion", &CDATATest<string_type, string_adaptor> ::testConversion));
    suiteOfTests->addTest(new TestCaller<CDATATest<string_type, string_adaptor> >("testConversionToText", &CDATATest<string_type, string_adaptor> ::testConversionToText));
    suiteOfTests->addTest(new TestCaller<CDATATest<string_type, string_adaptor> >("testEverythingElse", &CDATATest<string_type, string_adaptor> ::testEverythingElse));
    return suiteOfTests;
} // CDATATest_suite


#endif
