#include "JSCArrayBuffer.h"
#include "JSCArrayBufferView.h"
#include "JSCDataView.h"

namespace Arabica {
namespace DOM {

JSClassRef JSCDataView::Tmpl;

JSStaticValue JSCDataView::staticValues[] = {

	{ 0, 0, 0, 0 }
};

JSStaticFunction JSCDataView::staticFunctions[] = {
	{ "getInt8", getInt8Callback, kJSPropertyAttributeDontDelete },
	{ "getUint8", getUint8Callback, kJSPropertyAttributeDontDelete },
	{ "getInt16", getInt16Callback, kJSPropertyAttributeDontDelete },
	{ "getUint16", getUint16Callback, kJSPropertyAttributeDontDelete },
	{ "getInt32", getInt32Callback, kJSPropertyAttributeDontDelete },
	{ "getUint32", getUint32Callback, kJSPropertyAttributeDontDelete },
	{ "getFloat32", getFloat32Callback, kJSPropertyAttributeDontDelete },
	{ "getFloat64", getFloat64Callback, kJSPropertyAttributeDontDelete },
	{ "setInt8", setInt8Callback, kJSPropertyAttributeDontDelete },
	{ "setUint8", setUint8Callback, kJSPropertyAttributeDontDelete },
	{ "setInt16", setInt16Callback, kJSPropertyAttributeDontDelete },
	{ "setUint16", setUint16Callback, kJSPropertyAttributeDontDelete },
	{ "setInt32", setInt32Callback, kJSPropertyAttributeDontDelete },
	{ "setUint32", setUint32Callback, kJSPropertyAttributeDontDelete },
	{ "setFloat32", setFloat32Callback, kJSPropertyAttributeDontDelete },
	{ "setFloat64", setFloat64Callback, kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

JSObjectRef JSCDataView::jsConstructor(JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
	uscxml::DataView* localInstance = NULL;

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsObject(ctx, arguments[0]) && JSValueIsObjectOfClass(ctx, arguments[0], JSCArrayBuffer::getTmpl()) &&
	           JSValueIsNumber(ctx, arguments[1]) &&
	           JSValueIsNumber(ctx, arguments[2])) {

		uscxml::ArrayBuffer* localBuffer = ((struct JSCArrayBuffer::JSCArrayBufferPrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[0], exception)))->nativeObj;
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[1], exception);
		unsigned long localByteLength = (unsigned long)JSValueToNumber(ctx, arguments[2], exception);
		localInstance = new uscxml::DataView(localBuffer, localByteOffset, localByteLength);

	} else if (argumentCount == 2 &&
	           JSValueIsObject(ctx, arguments[0]) && JSValueIsObjectOfClass(ctx, arguments[0], JSCArrayBuffer::getTmpl()) &&
	           JSValueIsNumber(ctx, arguments[1])) {

		uscxml::ArrayBuffer* localBuffer = ((struct JSCArrayBuffer::JSCArrayBufferPrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[0], exception)))->nativeObj;
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[1], exception);
		localInstance = new uscxml::DataView(localBuffer, localByteOffset);

	} else if (argumentCount == 1 &&
	           JSValueIsObject(ctx, arguments[0]) && JSValueIsObjectOfClass(ctx, arguments[0], JSCArrayBuffer::getTmpl())) {

		uscxml::ArrayBuffer* localBuffer = ((struct JSCArrayBuffer::JSCArrayBufferPrivate*)JSObjectGetPrivate(JSValueToObject(ctx, arguments[0], exception)))->nativeObj;
		localInstance = new uscxml::DataView(localBuffer);

	}
	if (!localInstance) {
		JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling constructor for DataView");
		*exception = JSValueMakeString(ctx, exceptionString);
		JSStringRelease(exceptionString);
		return (JSObjectRef)JSValueMakeNull(ctx);
	}

	JSClassRef retClass = JSCDataView::getTmpl();

	struct JSCDataView::JSCDataViewPrivate* retPrivData = new JSCDataView::JSCDataViewPrivate();
	retPrivData->nativeObj = localInstance;

	JSObjectRef retObj = JSObjectMake(ctx, retClass, retPrivData);
	return retObj;
}

JSValueRef JSCDataView::getInt8Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		char retVal = privData->nativeObj->getInt8(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getInt8");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::getUint8Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		unsigned char retVal = privData->nativeObj->getUint8(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getUint8");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::getInt16Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsBoolean(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[1]);

		short retVal = privData->nativeObj->getInt16(localByteOffset, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		short retVal = privData->nativeObj->getInt16(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getInt16");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::getUint16Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsBoolean(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[1]);

		unsigned short retVal = privData->nativeObj->getUint16(localByteOffset, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		unsigned short retVal = privData->nativeObj->getUint16(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getUint16");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::getInt32Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsBoolean(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[1]);

		long retVal = privData->nativeObj->getInt32(localByteOffset, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		long retVal = privData->nativeObj->getInt32(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getInt32");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::getUint32Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsBoolean(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[1]);

		unsigned long retVal = privData->nativeObj->getUint32(localByteOffset, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		unsigned long retVal = privData->nativeObj->getUint32(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getUint32");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::getFloat32Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsBoolean(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[1]);

		float retVal = privData->nativeObj->getFloat32(localByteOffset, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		float retVal = privData->nativeObj->getFloat32(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getFloat32");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::getFloat64Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsBoolean(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[1]);

		double retVal = privData->nativeObj->getFloat64(localByteOffset, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	} else if (argumentCount == 1 &&
	           JSValueIsNumber(ctx, arguments[0])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);

		double retVal = privData->nativeObj->getFloat64(localByteOffset);

		JSValueRef jscRetVal = JSValueMakeNumber(ctx, retVal);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling getFloat64");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setInt8Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		char localValue = (char)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setInt8(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setInt8");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setUint8Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		unsigned char localValue = (unsigned char)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setUint8(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setUint8");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setInt16Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1]) &&
	           JSValueIsBoolean(ctx, arguments[2])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		short localValue = (short)JSValueToNumber(ctx, arguments[1], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[2]);

		privData->nativeObj->setInt16(localByteOffset, localValue, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		short localValue = (short)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setInt16(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setInt16");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setUint16Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1]) &&
	           JSValueIsBoolean(ctx, arguments[2])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		unsigned short localValue = (unsigned short)JSValueToNumber(ctx, arguments[1], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[2]);

		privData->nativeObj->setUint16(localByteOffset, localValue, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		unsigned short localValue = (unsigned short)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setUint16(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setUint16");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setInt32Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1]) &&
	           JSValueIsBoolean(ctx, arguments[2])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		long localValue = (long)JSValueToNumber(ctx, arguments[1], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[2]);

		privData->nativeObj->setInt32(localByteOffset, localValue, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		long localValue = (long)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setInt32(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setInt32");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setUint32Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1]) &&
	           JSValueIsBoolean(ctx, arguments[2])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		unsigned long localValue = (unsigned long)JSValueToNumber(ctx, arguments[1], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[2]);

		privData->nativeObj->setUint32(localByteOffset, localValue, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		unsigned long localValue = (unsigned long)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setUint32(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setUint32");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setFloat32Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1]) &&
	           JSValueIsBoolean(ctx, arguments[2])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		float localValue = (float)JSValueToNumber(ctx, arguments[1], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[2]);

		privData->nativeObj->setFloat32(localByteOffset, localValue, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		float localValue = (float)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setFloat32(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setFloat32");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

JSValueRef JSCDataView::setFloat64Callback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObj, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {

	struct JSCDataViewPrivate* privData = (struct JSCDataViewPrivate*)JSObjectGetPrivate(thisObj);

	if (false) {
	} else if (argumentCount == 3 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1]) &&
	           JSValueIsBoolean(ctx, arguments[2])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		double localValue = (double)JSValueToNumber(ctx, arguments[1], exception);
		bool localLittleEndian = JSValueToBoolean(ctx, arguments[2]);

		privData->nativeObj->setFloat64(localByteOffset, localValue, localLittleEndian);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	} else if (argumentCount == 2 &&
	           JSValueIsNumber(ctx, arguments[0]) &&
	           JSValueIsNumber(ctx, arguments[1])) {
		unsigned long localByteOffset = (unsigned long)JSValueToNumber(ctx, arguments[0], exception);
		double localValue = (double)JSValueToNumber(ctx, arguments[1], exception);

		privData->nativeObj->setFloat64(localByteOffset, localValue);

		JSValueRef jscRetVal = JSValueMakeUndefined(ctx);
		return jscRetVal;
	}

	JSStringRef exceptionString = JSStringCreateWithUTF8CString("Parameter mismatch while calling setFloat64");
	*exception = JSValueMakeString(ctx, exceptionString);
	JSStringRelease(exceptionString);
	return JSValueMakeUndefined(ctx);
}

}
}
