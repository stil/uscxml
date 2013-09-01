#include "JSCAttr.h"
#include "JSCCDATASection.h"
#include "JSCComment.h"
#include "JSCDOMImplementation.h"
#include "JSCDocument.h"
#include "JSCDocumentFragment.h"
#include "JSCDocumentType.h"
#include "JSCElement.h"
#include "JSCEntityReference.h"
#include "JSCNode.h"
#include "JSCNodeList.h"
#include "JSCProcessingInstruction.h"
#include "JSCText.h"

namespace Arabica {
namespace DOM {

JSClassRef JSCDocument::Tmpl;

JSStaticValue JSCDocument::staticValues[] = {
	{ "doctype", doctypeAttrGetter, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
	{ "implementation", implementationAttrGetter, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
	{ "documentElement", documentElementAttrGetter, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },
	{ "localStorage", localStorageCustomAttrGetter, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },

	{ 0, 0, 0, 0 }
};

JSStaticFunction JSCDocument::staticFunctions[] = {
	{ "createElement", createElementCallback, kJSPropertyAttributeDontDelete },
	{ "createDocumentFragment", createDocumentFragmentCallback, kJSPropertyAttributeDontDelete },
	{ "createTextNode", createTextNodeCallback, kJSPropertyAttributeDontDelete },
	{ "createComment", createCommentCallback, kJSPropertyAttributeDontDelete },
	{ "createCDATASection", createCDATASectionCallback, kJSPropertyAttributeDontDelete },
	{ "createProcessingInstruction", createProcessingInstructionCallback, kJSPropertyAttributeDontDelete },
	{ "createAttribute", createAttributeCallback, kJSPropertyAttributeDontDelete },
	{ "createEntityReference", createEntityReferenceCallback, kJSPropertyAttributeDontDelete },
	{ "getElementsByTagName", getElementsByTagNameCallback, kJSPropertyAttributeDontDelete },
	{ "importNode", importNodeCallback, kJSPropertyAttributeDontDelete },
	{ "createElementNS", createElementNSCallback, kJSPropertyAttributeDontDelete },
	{ "createAttributeNS", createAttributeNSCallback, kJSPropertyAttributeDontDelete },
	{ "getElementsByTagNameNS", getElementsByTagNameNSCallback, kJSPropertyAttributeDontDelete },
	{ "getElementById", getElementByIdCallback, kJSPropertyAttributeDontDelete },
	{ "evaluate", evaluateCustomCallback, kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

JSValueRef JSCDocument::doctypeAttrGetter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef *exception) {
	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(object);

	if (!privData->nativeObj->getDoctype()) return JSValueMakeUndefined(ctx);
	Arabica::DOM::DocumentType<std::string>* arabicaRet = new Arabica::DOM::DocumentType<std::string>(privData->nativeObj->getDoctype());

	JSClassRef arbaicaRetClass = JSCDocumentType::getTmpl();

	struct JSCDocumentType::JSCDocumentTypePrivate* retPrivData = new JSCDocumentType::JSCDocumentTypePrivate();
	retPrivData->dom = privData->dom;
	retPrivData->nativeObj = arabicaRet;

	JSObjectRef arbaicaRetObj = JSObjectMake(ctx, arbaicaRetClass, retPrivData);
	return arbaicaRetObj;
}


JSValueRef JSCDocument::implementationAttrGetter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef *exception) {
	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(object);

	if (!privData->nativeObj->getImplementation()) return JSValueMakeUndefined(ctx);
	Arabica::DOM::DOMImplementation<std::string>* arabicaRet = new Arabica::DOM::DOMImplementation<std::string>(privData->nativeObj->getImplementation());

	JSClassRef arbaicaRetClass = JSCDOMImplementation::getTmpl();

	struct JSCDOMImplementation::JSCDOMImplementationPrivate* retPrivData = new JSCDOMImplementation::JSCDOMImplementationPrivate();
	retPrivData->dom = privData->dom;
	retPrivData->nativeObj = arabicaRet;

	JSObjectRef arbaicaRetObj = JSObjectMake(ctx, arbaicaRetClass, retPrivData);
	return arbaicaRetObj;
}


JSValueRef JSCDocument::documentElementAttrGetter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef *exception) {
	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(object);

	if (!privData->nativeObj->getDocumentElement()) return JSValueMakeUndefined(ctx);
	Arabica::DOM::Element<std::string>* arabicaRet = new Arabica::DOM::Element<std::string>(privData->nativeObj->getDocumentElement());

	JSClassRef arbaicaRetClass = JSCElement::getTmpl();

	struct JSCElement::JSCElementPrivate* retPrivData = new JSCElement::JSCElementPrivate();
	retPrivData->dom = privData->dom;
	retPrivData->nativeObj = arabicaRet;

	JSObjectRef arbaicaRetObj = JSObjectMake(ctx, arbaicaRetClass, retPrivData);
	return arbaicaRetObj;
}


JSValueRef JSCDocument::createElementCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalTagName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localTagNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalTagName);
		char* localTagNameBuffer = new char[localTagNameMaxSize];
		JSStringGetUTF8CString(stringReflocalTagName, localTagNameBuffer, localTagNameMaxSize);
		std::string localTagName(localTagNameBuffer);
		JSStringRelease(stringReflocalTagName);
		free(localTagNameBuffer);


		Arabica::DOM::Element<std::string>* retVal = new Arabica::DOM::Element<std::string>(privData->nativeObj->createElement(localTagName));
		JSClassRef retClass = JSCElement::getTmpl();

		struct JSCElement::JSCElementPrivate* retPrivData = new JSCElement::JSCElementPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createElement");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createDocumentFragmentCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 0) {

		Arabica::DOM::DocumentFragment<std::string>* retVal = new Arabica::DOM::DocumentFragment<std::string>(privData->nativeObj->createDocumentFragment());
		JSClassRef retClass = JSCDocumentFragment::getTmpl();

		struct JSCDocumentFragment::JSCDocumentFragmentPrivate* retPrivData = new JSCDocumentFragment::JSCDocumentFragmentPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createDocumentFragment");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createTextNodeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalData = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localDataMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalData);
		char* localDataBuffer = new char[localDataMaxSize];
		JSStringGetUTF8CString(stringReflocalData, localDataBuffer, localDataMaxSize);
		std::string localData(localDataBuffer);
		JSStringRelease(stringReflocalData);
		free(localDataBuffer);


		Arabica::DOM::Text<std::string>* retVal = new Arabica::DOM::Text<std::string>(privData->nativeObj->createTextNode(localData));
		JSClassRef retClass = JSCText::getTmpl();

		struct JSCText::JSCTextPrivate* retPrivData = new JSCText::JSCTextPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createTextNode");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createCommentCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalData = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localDataMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalData);
		char* localDataBuffer = new char[localDataMaxSize];
		JSStringGetUTF8CString(stringReflocalData, localDataBuffer, localDataMaxSize);
		std::string localData(localDataBuffer);
		JSStringRelease(stringReflocalData);
		free(localDataBuffer);


		Arabica::DOM::Comment<std::string>* retVal = new Arabica::DOM::Comment<std::string>(privData->nativeObj->createComment(localData));
		JSClassRef retClass = JSCComment::getTmpl();

		struct JSCComment::JSCCommentPrivate* retPrivData = new JSCComment::JSCCommentPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createComment");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createCDATASectionCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalData = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localDataMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalData);
		char* localDataBuffer = new char[localDataMaxSize];
		JSStringGetUTF8CString(stringReflocalData, localDataBuffer, localDataMaxSize);
		std::string localData(localDataBuffer);
		JSStringRelease(stringReflocalData);
		free(localDataBuffer);


		Arabica::DOM::CDATASection<std::string>* retVal = new Arabica::DOM::CDATASection<std::string>(privData->nativeObj->createCDATASection(localData));
		JSClassRef retClass = JSCCDATASection::getTmpl();

		struct JSCCDATASection::JSCCDATASectionPrivate* retPrivData = new JSCCDATASection::JSCCDATASectionPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createCDATASection");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createProcessingInstructionCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalTarget = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localTargetMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalTarget);
		char* localTargetBuffer = new char[localTargetMaxSize];
		JSStringGetUTF8CString(stringReflocalTarget, localTargetBuffer, localTargetMaxSize);
		std::string localTarget(localTargetBuffer);
		JSStringRelease(stringReflocalTarget);
		free(localTargetBuffer);

		JSStringRef stringReflocalData = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localDataMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalData);
		char* localDataBuffer = new char[localDataMaxSize];
		JSStringGetUTF8CString(stringReflocalData, localDataBuffer, localDataMaxSize);
		std::string localData(localDataBuffer);
		JSStringRelease(stringReflocalData);
		free(localDataBuffer);


		Arabica::DOM::ProcessingInstruction<std::string>* retVal = new Arabica::DOM::ProcessingInstruction<std::string>(privData->nativeObj->createProcessingInstruction(localTarget, localData));
		JSClassRef retClass = JSCProcessingInstruction::getTmpl();

		struct JSCProcessingInstruction::JSCProcessingInstructionPrivate* retPrivData = new JSCProcessingInstruction::JSCProcessingInstructionPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createProcessingInstruction");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createAttributeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

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


		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->createAttribute(localName));
		JSClassRef retClass = JSCAttr::getTmpl();

		struct JSCAttr::JSCAttrPrivate* retPrivData = new JSCAttr::JSCAttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createAttribute");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createEntityReferenceCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

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


		Arabica::DOM::EntityReference<std::string>* retVal = new Arabica::DOM::EntityReference<std::string>(privData->nativeObj->createEntityReference(localName));
		JSClassRef retClass = JSCEntityReference::getTmpl();

		struct JSCEntityReference::JSCEntityReferencePrivate* retPrivData = new JSCEntityReference::JSCEntityReferencePrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createEntityReference");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::getElementsByTagNameCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalTagname = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localTagnameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalTagname);
		char* localTagnameBuffer = new char[localTagnameMaxSize];
		JSStringGetUTF8CString(stringReflocalTagname, localTagnameBuffer, localTagnameMaxSize);
		std::string localTagname(localTagnameBuffer);
		JSStringRelease(stringReflocalTagname);
		free(localTagnameBuffer);


		Arabica::DOM::NodeList<std::string>* retVal = new Arabica::DOM::NodeList<std::string>(privData->nativeObj->getElementsByTagName(localTagname));
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

JSValueRef JSCDocument::importNodeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsObject(ctx, arguments[0]) && JSValueIsObjectOfClass(ctx, arguments[0], JSCNode::getTmpl()) &&
	           JSValueIsBoolean(ctx, arguments[1])) {
		Arabica::DOM::Node<std::string>* localImportedNode = ((struct JSCNode::JSCNodePrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[0], exception)))->nativeObj;
		bool localDeep = JSValueToBoolean(ctx, arguments[1]);

		Arabica::DOM::Node<std::string>* retVal = new Arabica::DOM::Node<std::string>(privData->nativeObj->importNode(*localImportedNode, localDeep));
		JSClassRef retClass = JSCNode::getTmpl();

		struct JSCNode::JSCNodePrivate* retPrivData = new JSCNode::JSCNodePrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling importNode");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createElementNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

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

		JSStringRef stringReflocalQualifiedName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localQualifiedNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalQualifiedName);
		char* localQualifiedNameBuffer = new char[localQualifiedNameMaxSize];
		JSStringGetUTF8CString(stringReflocalQualifiedName, localQualifiedNameBuffer, localQualifiedNameMaxSize);
		std::string localQualifiedName(localQualifiedNameBuffer);
		JSStringRelease(stringReflocalQualifiedName);
		free(localQualifiedNameBuffer);


		Arabica::DOM::Element<std::string>* retVal = new Arabica::DOM::Element<std::string>(privData->nativeObj->createElementNS(localNamespaceURI, localQualifiedName));
		JSClassRef retClass = JSCElement::getTmpl();

		struct JSCElement::JSCElementPrivate* retPrivData = new JSCElement::JSCElementPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createElementNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::createAttributeNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

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

		JSStringRef stringReflocalQualifiedName = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localQualifiedNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalQualifiedName);
		char* localQualifiedNameBuffer = new char[localQualifiedNameMaxSize];
		JSStringGetUTF8CString(stringReflocalQualifiedName, localQualifiedNameBuffer, localQualifiedNameMaxSize);
		std::string localQualifiedName(localQualifiedNameBuffer);
		JSStringRelease(stringReflocalQualifiedName);
		free(localQualifiedNameBuffer);


		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->createAttributeNS(localNamespaceURI, localQualifiedName));
		JSClassRef retClass = JSCAttr::getTmpl();

		struct JSCAttr::JSCAttrPrivate* retPrivData = new JSCAttr::JSCAttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createAttributeNS");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDocument::getElementsByTagNameNSCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

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

JSValueRef JSCDocument::getElementByIdCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDocumentPrivate* privData = (struct JSCDocumentPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalElementId = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localElementIdMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalElementId);
		char* localElementIdBuffer = new char[localElementIdMaxSize];
		JSStringGetUTF8CString(stringReflocalElementId, localElementIdBuffer, localElementIdMaxSize);
		std::string localElementId(localElementIdBuffer);
		JSStringRelease(stringReflocalElementId);
		free(localElementIdBuffer);


		Arabica::DOM::Element<std::string>* retVal = new Arabica::DOM::Element<std::string>(privData->nativeObj->getElementById(localElementId));
		JSClassRef retClass = JSCElement::getTmpl();

		struct JSCElement::JSCElementPrivate* retPrivData = new JSCElement::JSCElementPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getElementById");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

}
}
