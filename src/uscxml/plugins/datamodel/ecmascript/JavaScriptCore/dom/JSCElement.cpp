#include "JSCAttr.h"
#include "JSCElement.h"
#include "JSCNode.h"
#include "JSCNodeList.h"

namespace Arabica {
namespace DOM {

JSClassRef JSCElement::Tmpl;

JSStaticValue JSCElement::staticValues[] = {
	{ "tagName", tagNameAttrGetter, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },

	{ 0, 0, 0, 0 }
};

JSStaticFunction JSCElement::staticFunctions[] = {
	{ "getAttribute", getAttributeCallback, kJSPropertyAttributeDontDelete },
	{ "setAttribute", setAttributeCallback, kJSPropertyAttributeDontDelete },
	{ "removeAttribute", removeAttributeCallback, kJSPropertyAttributeDontDelete },
	{ "getAttributeNode", getAttributeNodeCallback, kJSPropertyAttributeDontDelete },
	{ "setAttributeNode", setAttributeNodeCallback, kJSPropertyAttributeDontDelete },
	{ "removeAttributeNode", removeAttributeNodeCallback, kJSPropertyAttributeDontDelete },
	{ "getElementsByTagName", getElementsByTagNameCallback, kJSPropertyAttributeDontDelete },
	{ "getAttributeNS", getAttributeNSCallback, kJSPropertyAttributeDontDelete },
	{ "setAttributeNS", setAttributeNSCallback, kJSPropertyAttributeDontDelete },
	{ "removeAttributeNS", removeAttributeNSCallback, kJSPropertyAttributeDontDelete },
	{ "getAttributeNodeNS", getAttributeNodeNSCallback, kJSPropertyAttributeDontDelete },
	{ "setAttributeNodeNS", setAttributeNodeNSCallback, kJSPropertyAttributeDontDelete },
	{ "getElementsByTagNameNS", getElementsByTagNameNSCallback, kJSPropertyAttributeDontDelete },
	{ "hasAttribute", hasAttributeCallback, kJSPropertyAttributeDontDelete },
	{ "hasAttributeNS", hasAttributeNSCallback, kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

JSValueRef JSCElement::tagNameAttrGetter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef *exception) {
	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(object);

	JSStringRef stringRef = JSStringCreateWithUTF8CString(privData->nativeObj->getTagName().c_str());
	JSValueRef retVal = JSValueMakeString(ctx, stringRef);
	JSStringRelease(stringRef);
	return retVal;
}


JSValueRef JSCElement::getAttributeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalName);
		char* localNameBuffer = new char[localNameMaxSize];
		JSStringGetUTF8CString(stringReflocalName, localNameBuffer, localNameMaxSize);
		std::string localName(localNameBuffer);
		JSStringRelease(stringReflocalName);
		free(localNameBuffer);


		std::string retVal = privData->nativeObj->getAttribute(localName);

		JSStringRef jscString = JSStringCreateWithUTF8CString(retVal.c_str());
		JSValueRef jscRetVal = JSValueMakeString(ctx, jscString);
		JSStringRelease(jscString);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getAttribute");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::setAttributeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalName);
		char* localNameBuffer = new char[localNameMaxSize];
		JSStringGetUTF8CString(stringReflocalName, localNameBuffer, localNameMaxSize);
		std::string localName(localNameBuffer);
		JSStringRelease(stringReflocalName);
		free(localNameBuffer);

		JSStringRef stringReflocalValue = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localValueMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalValue);
		char* localValueBuffer = new char[localValueMaxSize];
		JSStringGetUTF8CString(stringReflocalValue, localValueBuffer, localValueMaxSize);
		std::string localValue(localValueBuffer);
		JSStringRelease(stringReflocalValue);
		free(localValueBuffer);


		privData->nativeObj->setAttribute(localName, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setAttribute");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::removeAttributeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalName);
		char* localNameBuffer = new char[localNameMaxSize];
		JSStringGetUTF8CString(stringReflocalName, localNameBuffer, localNameMaxSize);
		std::string localName(localNameBuffer);
		JSStringRelease(stringReflocalName);
		free(localNameBuffer);


		privData->nativeObj->removeAttribute(localName);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling removeAttribute");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::getAttributeNodeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalName);
		char* localNameBuffer = new char[localNameMaxSize];
		JSStringGetUTF8CString(stringReflocalName, localNameBuffer, localNameMaxSize);
		std::string localName(localNameBuffer);
		JSStringRelease(stringReflocalName);
		free(localNameBuffer);


		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->getAttributeNode(localName));
		JSClassRef retClass = JSCAttr::getTmpl();

		struct JSCAttr::JSCAttrPrivate* retPrivData = new JSCAttr::JSCAttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getAttributeNode");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::setAttributeNodeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsObject(ctx, arguments[0]) && JSValueIsObjectOfClass(ctx, arguments[0], JSCAttr::getTmpl())) {
		Arabica::DOM::Attr<std::string>* localNewAttr = ((struct JSCAttr::JSCAttrPrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[0], exception)))->nativeObj;

		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->setAttributeNode(*localNewAttr));
		JSClassRef retClass = JSCAttr::getTmpl();

		struct JSCAttr::JSCAttrPrivate* retPrivData = new JSCAttr::JSCAttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setAttributeNode");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::removeAttributeNodeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsObject(ctx, arguments[0]) && JSValueIsObjectOfClass(ctx, arguments[0], JSCAttr::getTmpl())) {
		Arabica::DOM::Attr<std::string>* localOldAttr = ((struct JSCAttr::JSCAttrPrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[0], exception)))->nativeObj;

		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->removeAttributeNode(*localOldAttr));
		JSClassRef retClass = JSCAttr::getTmpl();

		struct JSCAttr::JSCAttrPrivate* retPrivData = new JSCAttr::JSCAttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling removeAttributeNode");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::getElementsByTagNameCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalName);
		char* localNameBuffer = new char[localNameMaxSize];
		JSStringGetUTF8CString(stringReflocalName, localNameBuffer, localNameMaxSize);
		std::string localName(localNameBuffer);
		JSStringRelease(stringReflocalName);
		free(localNameBuffer);


		Arabica::DOM::NodeList<std::string>* retVal = new Arabica::DOM::NodeList<std::string>(privData->nativeObj->getElementsByTagName(localName));
		JSClassRef retClass = JSCNodeList::getTmpl();

		struct JSCNodeList::JSCNodeListPrivate* retPrivData = new JSCNodeList::JSCNodeListPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getElementsByTagName");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::getAttributeNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalNamespaceURI = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNamespaceURIMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalNamespaceURI);
		char* localNamespaceURIBuffer = new char[localNamespaceURIMaxSize];
		JSStringGetUTF8CString(stringReflocalNamespaceURI, localNamespaceURIBuffer, localNamespaceURIMaxSize);
		std::string localNamespaceURI(localNamespaceURIBuffer);
		JSStringRelease(stringReflocalNamespaceURI);
		free(localNamespaceURIBuffer);

		JSStringRef stringReflocalLocalName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localLocalNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalLocalName);
		char* localLocalNameBuffer = new char[localLocalNameMaxSize];
		JSStringGetUTF8CString(stringReflocalLocalName, localLocalNameBuffer, localLocalNameMaxSize);
		std::string localLocalName(localLocalNameBuffer);
		JSStringRelease(stringReflocalLocalName);
		free(localLocalNameBuffer);


		std::string retVal = privData->nativeObj->getAttributeNS(localNamespaceURI, localLocalName);

		JSStringRef jscString = JSStringCreateWithUTF8CString(retVal.c_str());
		JSValueRef jscRetVal = JSValueMakeString(ctx, jscString);
		JSStringRelease(jscString);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getAttributeNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::setAttributeNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1]) &&
	           JSValueIsString(ctx, arguments[2])) {
		JSStringRef stringReflocalNamespaceURI = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNamespaceURIMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalNamespaceURI);
		char* localNamespaceURIBuffer = new char[localNamespaceURIMaxSize];
		JSStringGetUTF8CString(stringReflocalNamespaceURI, localNamespaceURIBuffer, localNamespaceURIMaxSize);
		std::string localNamespaceURI(localNamespaceURIBuffer);
		JSStringRelease(stringReflocalNamespaceURI);
		free(localNamespaceURIBuffer);

		JSStringRef stringReflocalQualifiedName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localQualifiedNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalQualifiedName);
		char* localQualifiedNameBuffer = new char[localQualifiedNameMaxSize];
		JSStringGetUTF8CString(stringReflocalQualifiedName, localQualifiedNameBuffer, localQualifiedNameMaxSize);
		std::string localQualifiedName(localQualifiedNameBuffer);
		JSStringRelease(stringReflocalQualifiedName);
		free(localQualifiedNameBuffer);

		JSStringRef stringReflocalValue = JSValueToStringCopy(ctx, arguments[2], exception);
		size_t localValueMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalValue);
		char* localValueBuffer = new char[localValueMaxSize];
		JSStringGetUTF8CString(stringReflocalValue, localValueBuffer, localValueMaxSize);
		std::string localValue(localValueBuffer);
		JSStringRelease(stringReflocalValue);
		free(localValueBuffer);


		privData->nativeObj->setAttributeNS(localNamespaceURI, localQualifiedName, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setAttributeNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::removeAttributeNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalNamespaceURI = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNamespaceURIMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalNamespaceURI);
		char* localNamespaceURIBuffer = new char[localNamespaceURIMaxSize];
		JSStringGetUTF8CString(stringReflocalNamespaceURI, localNamespaceURIBuffer, localNamespaceURIMaxSize);
		std::string localNamespaceURI(localNamespaceURIBuffer);
		JSStringRelease(stringReflocalNamespaceURI);
		free(localNamespaceURIBuffer);

		JSStringRef stringReflocalLocalName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localLocalNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalLocalName);
		char* localLocalNameBuffer = new char[localLocalNameMaxSize];
		JSStringGetUTF8CString(stringReflocalLocalName, localLocalNameBuffer, localLocalNameMaxSize);
		std::string localLocalName(localLocalNameBuffer);
		JSStringRelease(stringReflocalLocalName);
		free(localLocalNameBuffer);


		privData->nativeObj->removeAttributeNS(localNamespaceURI, localLocalName);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling removeAttributeNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::getAttributeNodeNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalNamespaceURI = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNamespaceURIMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalNamespaceURI);
		char* localNamespaceURIBuffer = new char[localNamespaceURIMaxSize];
		JSStringGetUTF8CString(stringReflocalNamespaceURI, localNamespaceURIBuffer, localNamespaceURIMaxSize);
		std::string localNamespaceURI(localNamespaceURIBuffer);
		JSStringRelease(stringReflocalNamespaceURI);
		free(localNamespaceURIBuffer);

		JSStringRef stringReflocalLocalName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localLocalNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalLocalName);
		char* localLocalNameBuffer = new char[localLocalNameMaxSize];
		JSStringGetUTF8CString(stringReflocalLocalName, localLocalNameBuffer, localLocalNameMaxSize);
		std::string localLocalName(localLocalNameBuffer);
		JSStringRelease(stringReflocalLocalName);
		free(localLocalNameBuffer);


		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->getAttributeNodeNS(localNamespaceURI, localLocalName));
		JSClassRef retClass = JSCAttr::getTmpl();

		struct JSCAttr::JSCAttrPrivate* retPrivData = new JSCAttr::JSCAttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getAttributeNodeNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::setAttributeNodeNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsObject(ctx, arguments[0]) && JSValueIsObjectOfClass(ctx, arguments[0], JSCAttr::getTmpl())) {
		Arabica::DOM::Attr<std::string>* localNewAttr = ((struct JSCAttr::JSCAttrPrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[0], exception)))->nativeObj;

		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->setAttributeNodeNS(*localNewAttr));
		JSClassRef retClass = JSCAttr::getTmpl();

		struct JSCAttr::JSCAttrPrivate* retPrivData = new JSCAttr::JSCAttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setAttributeNodeNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::getElementsByTagNameNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalNamespaceURI = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNamespaceURIMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalNamespaceURI);
		char* localNamespaceURIBuffer = new char[localNamespaceURIMaxSize];
		JSStringGetUTF8CString(stringReflocalNamespaceURI, localNamespaceURIBuffer, localNamespaceURIMaxSize);
		std::string localNamespaceURI(localNamespaceURIBuffer);
		JSStringRelease(stringReflocalNamespaceURI);
		free(localNamespaceURIBuffer);

		JSStringRef stringReflocalLocalName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localLocalNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalLocalName);
		char* localLocalNameBuffer = new char[localLocalNameMaxSize];
		JSStringGetUTF8CString(stringReflocalLocalName, localLocalNameBuffer, localLocalNameMaxSize);
		std::string localLocalName(localLocalNameBuffer);
		JSStringRelease(stringReflocalLocalName);
		free(localLocalNameBuffer);


		Arabica::DOM::NodeList<std::string>* retVal = new Arabica::DOM::NodeList<std::string>(privData->nativeObj->getElementsByTagNameNS(localNamespaceURI, localLocalName));
		JSClassRef retClass = JSCNodeList::getTmpl();

		struct JSCNodeList::JSCNodeListPrivate* retPrivData = new JSCNodeList::JSCNodeListPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getElementsByTagNameNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::hasAttributeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalName);
		char* localNameBuffer = new char[localNameMaxSize];
		JSStringGetUTF8CString(stringReflocalName, localNameBuffer, localNameMaxSize);
		std::string localName(localNameBuffer);
		JSStringRelease(stringReflocalName);
		free(localNameBuffer);


		bool retVal = privData->nativeObj->hasAttribute(localName);

		JSValueRef jscRetVal = JSValueMakeBoolean(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling hasAttribute");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCElement::hasAttributeNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCElementPrivate* privData = (struct JSCElementPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalNamespaceURI = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localNamespaceURIMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalNamespaceURI);
		char* localNamespaceURIBuffer = new char[localNamespaceURIMaxSize];
		JSStringGetUTF8CString(stringReflocalNamespaceURI, localNamespaceURIBuffer, localNamespaceURIMaxSize);
		std::string localNamespaceURI(localNamespaceURIBuffer);
		JSStringRelease(stringReflocalNamespaceURI);
		free(localNamespaceURIBuffer);

		JSStringRef stringReflocalLocalName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localLocalNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalLocalName);
		char* localLocalNameBuffer = new char[localLocalNameMaxSize];
		JSStringGetUTF8CString(stringReflocalLocalName, localLocalNameBuffer, localLocalNameMaxSize);
		std::string localLocalName(localLocalNameBuffer);
		JSStringRelease(stringReflocalLocalName);
		free(localLocalNameBuffer);


		bool retVal = privData->nativeObj->hasAttributeNS(localNamespaceURI, localLocalName);

		JSValueRef jscRetVal = JSValueMakeBoolean(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling hasAttributeNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

}
}
