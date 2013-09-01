#include "JSCStorage.h"

namespace Arabica {
namespace DOM {

JSClassRef JSCStorage::Tmpl;

JSStaticValue JSCStorage::staticValues[] = {
	{ "length", lengthAttrGetter, 0, kJSPropertyAttributeDontDelete | kJSPropertyAttributeReadOnly },

	{ 0, 0, 0, 0 }
};

JSStaticFunction JSCStorage::staticFunctions[] = {
	{ "key", keyCallback, kJSPropertyAttributeDontDelete },
	{ "getItem", getItemCallback, kJSPropertyAttributeDontDelete },
	{ "setItem", setItemCallback, kJSPropertyAttributeDontDelete },
	{ "removeItem", removeItemCallback, kJSPropertyAttributeDontDelete },
	{ "clear", clearCallback, kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

JSValueRef JSCStorage::lengthAttrGetter(JSContextRef ctx, JSObjectRef object, JSStringRef propertyName, JSValueRef *exception) {
	struct JSCStoragePrivate* privData = (struct JSCStoragePrivate*)JSObjectGetPrivate(object);

	return JSValueMakeNumber(ctx, privData->nativeObj->getLength());
}


JSValueRef JSCStorage::keyCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCStoragePrivate* privData = (struct JSCStoragePrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localIndex = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		std::string retVal = privData->nativeObj->key(localIndex);

		JSStringRef jscString = JSStringCreateWithUTF8CString(retVal.c_str());
		JSValueRef jscRetVal = JSValueMakeString(ctx, jscString);
		JSStringRelease(jscString);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling key");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCStorage::getItemCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCStoragePrivate* privData = (struct JSCStoragePrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalKey = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localKeyMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalKey);
		char* localKeyBuffer = new char[localKeyMaxSize];
		JSStringGetUTF8CString(stringReflocalKey, localKeyBuffer, localKeyMaxSize);
		std::string localKey(localKeyBuffer);
		JSStringRelease(stringReflocalKey);
		free(localKeyBuffer);


		std::string retVal = privData->nativeObj->getItem(localKey);

		JSStringRef jscString = JSStringCreateWithUTF8CString(retVal.c_str());
		JSValueRef jscRetVal = JSValueMakeString(ctx, jscString);
		JSStringRelease(jscString);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getItem");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCStorage::setItemCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCStoragePrivate* privData = (struct JSCStoragePrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsString(ctx, arguments[0]) &&
	           JSValueIsString(ctx, arguments[1])) {
		JSStringRef stringReflocalKey = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localKeyMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalKey);
		char* localKeyBuffer = new char[localKeyMaxSize];
		JSStringGetUTF8CString(stringReflocalKey, localKeyBuffer, localKeyMaxSize);
		std::string localKey(localKeyBuffer);
		JSStringRelease(stringReflocalKey);
		free(localKeyBuffer);

		JSStringRef stringReflocalValue = JSValueToStringCopy(ctx, arguments[1], exception);
		size_t localValueMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalValue);
		char* localValueBuffer = new char[localValueMaxSize];
		JSStringGetUTF8CString(stringReflocalValue, localValueBuffer, localValueMaxSize);
		std::string localValue(localValueBuffer);
		JSStringRelease(stringReflocalValue);
		free(localValueBuffer);


		privData->nativeObj->setItem(localKey, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setItem");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCStorage::removeItemCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCStoragePrivate* privData = (struct JSCStoragePrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsString(ctx, arguments[0])) {
		JSStringRef stringReflocalKey = JSValueToStringCopy(ctx, arguments[0], exception);
		size_t localKeyMaxSize = JSStringGetMaximumUTF8CStringSize(stringReflocalKey);
		char* localKeyBuffer = new char[localKeyMaxSize];
		JSStringGetUTF8CString(stringReflocalKey, localKeyBuffer, localKeyMaxSize);
		std::string localKey(localKeyBuffer);
		JSStringRelease(stringReflocalKey);
		free(localKeyBuffer);


		privData->nativeObj->removeItem(localKey);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling removeItem");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCStorage::clearCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCStoragePrivate* privData = (struct JSCStoragePrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 0) {

		privData->nativeObj->clear();

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling clear");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

}
}
