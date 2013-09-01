#include "JSCDOMImplementation.h"
#include "JSCDocument.h"
#include "JSCDocumentType.h"

namespace Arabica {
namespace DOM {

JSClassRef JSCDOMImplementation::Tmpl;

JSStaticValue JSCDOMImplementation::staticValues[] = {

	{ 0, 0, 0, 0 }
};

JSStaticFunction JSCDOMImplementation::staticFunctions[] = {
	{ "hasFeature", hasFeatureCallback, kJSPropertyAttributeDontDelete },
	{ "createDocumentType", createDocumentTypeCallback, kJSPropertyAttributeDontDelete },
	{ "createDocument", createDocumentCallback, kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

JSValueRef JSCDOMImplementation::hasFeatureCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDOMImplementationPrivate* privData = (struct JSCDOMImplementationPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalFeature = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localFeatureMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalFeature);
		char* localFeatureBuffer = new char[localFeatureMaxSize];
		JSStringGetUTF8CString(stringReflocalFeature, localFeatureBuffer, localFeatureMaxSize);
		std::string localFeature(localFeatureBuffer);
		JSStringRelease(stringReflocalFeature);
		free(localFeatureBuffer);

		JSStringRef stringReflocalVersion = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localVersionMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalVersion);
		char* localVersionBuffer = new char[localVersionMaxSize];
		JSStringGetUTF8CString(stringReflocalVersion, localVersionBuffer, localVersionMaxSize);
		std::string localVersion(localVersionBuffer);
		JSStringRelease(stringReflocalVersion);
		free(localVersionBuffer);


		bool retVal = privData->nativeObj->hasFeature(localFeature, localVersion);

		JSValueRef jscRetVal = JSValueMakeBoolean(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling hasFeature");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDOMImplementation::createDocumentTypeCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDOMImplementationPrivate* privData = (struct JSCDOMImplementationPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1]) &&
	           JSValueIsString(ctx, arguments[2])) {
		JSStringRef stringReflocalQualifiedName = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localQualifiedNameMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalQualifiedName);
		char* localQualifiedNameBuffer = new char[localQualifiedNameMaxSize];
		JSStringGetUTF8CString(stringReflocalQualifiedName, localQualifiedNameBuffer, localQualifiedNameMaxSize);
		std::string localQualifiedName(localQualifiedNameBuffer);
		JSStringRelease(stringReflocalQualifiedName);
		free(localQualifiedNameBuffer);

		JSStringRef stringReflocalPublicId = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localPublicIdMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalPublicId);
		char* localPublicIdBuffer = new char[localPublicIdMaxSize];
		JSStringGetUTF8CString(stringReflocalPublicId, localPublicIdBuffer, localPublicIdMaxSize);
		std::string localPublicId(localPublicIdBuffer);
		JSStringRelease(stringReflocalPublicId);
		free(localPublicIdBuffer);

		JSStringRef stringReflocalSystemId = JSValueToStringCopy(ctx, arguments[2], exception);
		size_t localSystemIdMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalSystemId);
		char* localSystemIdBuffer = new char[localSystemIdMaxSize];
		JSStringGetUTF8CString(stringReflocalSystemId, localSystemIdBuffer, localSystemIdMaxSize);
		std::string localSystemId(localSystemIdBuffer);
		JSStringRelease(stringReflocalSystemId);
		free(localSystemIdBuffer);


		Arabica::DOM::DocumentType<std::string>* retVal = new Arabica::DOM::DocumentType<std::string>(privData->nativeObj->createDocumentType(localQualifiedName, localPublicId, localSystemId));
		JSClassRef retClass = JSCDocumentType::getTmpl();

		struct JSCDocumentType::JSCDocumentTypePrivate* retPrivData = new JSCDocumentType::JSCDocumentTypePrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createDocumentType");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDOMImplementation::createDocumentCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDOMImplementationPrivate* privData = (struct JSCDOMImplementationPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1]) &&
	           JSValueIsObject(ctx, arguments[2]) && JSValueIsObjectOfClass(ctx, arguments[2], JSCDocumentType::getTmpl())) {
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

		Arabica::DOM::DocumentType<std::string>* localDoctype = ((struct JSCDocumentType::JSCDocumentTypePrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[2], exception)))->nativeObj;

		Arabica::DOM::Document<std::string>* retVal = new Arabica::DOM::Document<std::string>(privData->nativeObj->createDocument(localNamespaceURI, localQualifiedName, *localDoctype));
		JSClassRef retClass = JSCDocument::getTmpl();

		struct JSCDocument::JSCDocumentPrivate* retPrivData = new JSCDocument::JSCDocumentPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);

		return retObj;

	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling createDocument");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

}
}
