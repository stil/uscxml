#include "V8ArrayBuffer.h"
#include "V8ArrayBufferView.h"
#include "V8Float64Array.h"

namespace Arabica {
namespace DOM {

v8::Persistent<v8::FunctionTemplate> V8Float64Array::Tmpl;
v8::Persistent<v8::FunctionTemplate> V8Float64Array::Constr;

v8::Handle<v8::Value> V8Float64Array::constructor(const v8::Arguments& args) {
	if (!args.IsConstructCall())
		return v8::ThrowException(v8::String::New("Cannot call constructor as function"));

	uscxml::Float64Array* localInstance = NULL;
	if (false) {
	} else if (args.Length() == 3 &&
	           args[0]->IsObject() && V8ArrayBuffer::hasInstance(args[0]) &&
	           args[1]->IsUint32() &&
	           args[2]->IsUint32()) {

		uscxml::ArrayBuffer* localBuffer = V8DOM::toClassPtr<V8ArrayBuffer::V8ArrayBufferPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		unsigned long localByteOffset = args[1]->ToNumber()->Uint32Value();
		unsigned long localLength = args[2]->ToNumber()->Uint32Value();
		localInstance = new uscxml::Float64Array(localBuffer, localByteOffset, localLength);

	} else if (args.Length() == 2 &&
	           args[0]->IsObject() && V8ArrayBuffer::hasInstance(args[0]) &&
	           args[1]->IsUint32()) {

		uscxml::ArrayBuffer* localBuffer = V8DOM::toClassPtr<V8ArrayBuffer::V8ArrayBufferPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		unsigned long localByteOffset = args[1]->ToNumber()->Uint32Value();
		localInstance = new uscxml::Float64Array(localBuffer, localByteOffset);

	} else if (args.Length() == 1 &&
	           args[0]->IsObject() && V8Float64Array::hasInstance(args[0])) {

		uscxml::Float64Array* localArray = V8DOM::toClassPtr<V8Float64Array::V8Float64ArrayPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		localInstance = new uscxml::Float64Array(localArray);

	} else if (args.Length() == 1 &&
	           args[0]->IsObject() && V8ArrayBuffer::hasInstance(args[0])) {

		uscxml::ArrayBuffer* localBuffer = V8DOM::toClassPtr<V8ArrayBuffer::V8ArrayBufferPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		localInstance = new uscxml::Float64Array(localBuffer);

	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {

		unsigned long localLength = args[0]->ToNumber()->Uint32Value();
		localInstance = new uscxml::Float64Array(localLength);

	} else if (args.Length() == 1 &&
	           args[0]->IsArray()) {

		std::vector<double> localArray;
		v8::Handle<v8::Array> localArrayArray(v8::Array::Cast(*args[0]));
		for (int i = 0; i < localArrayArray->Length(); i++) {
			localArray.push_back(localArrayArray->Get(i)->ToNumber()->Value());
		}
		localInstance = new uscxml::Float64Array(localArray);

	}
	if (!localInstance) {
		throw V8Exception("Parameter mismatch while calling constructor for Float64Array");
		return v8::Undefined();
	}

	v8::Handle<v8::Function> retCtor = V8Float64Array::getTmpl()->GetFunction();
	v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

	struct V8Float64Array::V8Float64ArrayPrivate* retPrivData = new V8Float64Array::V8Float64ArrayPrivate();
	retPrivData->nativeObj = localInstance;

	retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

	retObj.MakeWeak(0, V8Float64Array::jsDestructor);
	return retObj;
}

v8::Handle<v8::Value> V8Float64Array::lengthAttrGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
	v8::Local<v8::Object> self = info.Holder();
	struct V8Float64ArrayPrivate* privData = V8DOM::toClassPtr<V8Float64ArrayPrivate >(self->GetInternalField(0));

	return v8::Integer::New(privData->nativeObj->getLength());
}

v8::Handle<v8::Value> V8Float64Array::getCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8Float64ArrayPrivate* privData = V8DOM::toClassPtr<V8Float64ArrayPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {
		unsigned long localIndex = args[0]->ToNumber()->Uint32Value();

		double retVal = privData->nativeObj->get(localIndex);

		return v8::Number::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling get");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Float64Array::setCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8Float64ArrayPrivate* privData = V8DOM::toClassPtr<V8Float64ArrayPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsObject() && V8Float64Array::hasInstance(args[0]) &&
	           args[1]->IsUint32()) {
		uscxml::Float64Array* localArray = V8DOM::toClassPtr<V8Float64Array::V8Float64ArrayPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		unsigned long localOffset = args[1]->ToNumber()->Uint32Value();

		privData->nativeObj->set(localArray, localOffset);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsUint32() &&
	           args[1]->IsNumber()) {
		unsigned long localIndex = args[0]->ToNumber()->Uint32Value();
		double localValue = args[1]->ToNumber()->Value();

		privData->nativeObj->set(localIndex, localValue);

		return v8::Undefined();
	} else if (args.Length() == 2 &&
	           args[0]->IsArray() &&
	           args[1]->IsUint32()) {
		std::vector<double> localArray;
		v8::Handle<v8::Array> localArrayArray(v8::Array::Cast(*args[0]));
		for (int i = 0; i < localArrayArray->Length(); i++) {
			localArray.push_back(localArrayArray->Get(i)->ToNumber()->Value());
		}
		unsigned long localOffset = args[1]->ToNumber()->Uint32Value();

		privData->nativeObj->set(localArray, localOffset);

		return v8::Undefined();
	} else if (args.Length() == 1 &&
	           args[0]->IsObject() && V8Float64Array::hasInstance(args[0])) {
		uscxml::Float64Array* localArray = V8DOM::toClassPtr<V8Float64Array::V8Float64ArrayPrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;

		privData->nativeObj->set(localArray);

		return v8::Undefined();
	} else if (args.Length() == 1 &&
	           args[0]->IsArray()) {
		std::vector<double> localArray;
		v8::Handle<v8::Array> localArrayArray(v8::Array::Cast(*args[0]));
		for (int i = 0; i < localArrayArray->Length(); i++) {
			localArray.push_back(localArrayArray->Get(i)->ToNumber()->Value());
		}

		privData->nativeObj->set(localArray);

		return v8::Undefined();
	}
	throw V8Exception("Parameter mismatch while calling set");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Float64Array::subarrayCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8Float64ArrayPrivate* privData = V8DOM::toClassPtr<V8Float64ArrayPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsInt32() &&
	           args[1]->IsInt32()) {
		long localStart = args[0]->ToNumber()->Int32Value();
		long localEnd = args[1]->ToNumber()->Int32Value();

		uscxml::Float64Array* retVal = new uscxml::Float64Array(privData->nativeObj->subarray(localStart, localEnd));
		v8::Handle<v8::Function> retCtor = V8Float64Array::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Float64Array::V8Float64ArrayPrivate* retPrivData = new V8Float64Array::V8Float64ArrayPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Float64Array::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling subarray");
	return v8::Undefined();
}
bool V8Float64Array::hasInstance(v8::Handle<v8::Value> value) {
	return getTmpl()->HasInstance(value);
}

}
}
