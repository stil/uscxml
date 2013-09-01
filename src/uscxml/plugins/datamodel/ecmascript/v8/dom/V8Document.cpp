#include "V8Attr.h"
#include "V8CDATASection.h"
#include "V8Comment.h"
#include "V8DOMImplementation.h"
#include "V8Document.h"
#include "V8DocumentFragment.h"
#include "V8DocumentType.h"
#include "V8Element.h"
#include "V8EntityReference.h"
#include "V8Node.h"
#include "V8NodeList.h"
#include "V8ProcessingInstruction.h"
#include "V8Text.h"

namespace Arabica {
namespace DOM {

v8::Persistent<v8::FunctionTemplate> V8Document::Tmpl;

v8::Handle<v8::Value> V8Document::doctypeAttrGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
	v8::Local<v8::Object> self = info.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));

	if (!privData->nativeObj->getDoctype()) return v8::Undefined();
	Arabica::DOM::DocumentType<std::string>* arbaicaRet = new Arabica::DOM::DocumentType<std::string>(privData->nativeObj->getDoctype());

	v8::Handle<v8::Function> arbaicaRetCtor = V8DocumentType::getTmpl()->GetFunction();
	v8::Persistent<v8::Object> arbaicaRetObj = v8::Persistent<v8::Object>::New(arbaicaRetCtor->NewInstance());

	struct V8DocumentType::V8DocumentTypePrivate* retPrivData = new V8DocumentType::V8DocumentTypePrivate();
	retPrivData->dom = privData->dom;
	retPrivData->nativeObj = arbaicaRet;

	arbaicaRetObj->SetInternalField(0, V8DOM::toExternal(retPrivData));
	arbaicaRetObj.MakeWeak(0, V8DocumentType::jsDestructor);
	return arbaicaRetObj;

}

v8::Handle<v8::Value> V8Document::implementationAttrGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
	v8::Local<v8::Object> self = info.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));

	if (!privData->nativeObj->getImplementation()) return v8::Undefined();
	Arabica::DOM::DOMImplementation<std::string>* arbaicaRet = new Arabica::DOM::DOMImplementation<std::string>(privData->nativeObj->getImplementation());

	v8::Handle<v8::Function> arbaicaRetCtor = V8DOMImplementation::getTmpl()->GetFunction();
	v8::Persistent<v8::Object> arbaicaRetObj = v8::Persistent<v8::Object>::New(arbaicaRetCtor->NewInstance());

	struct V8DOMImplementation::V8DOMImplementationPrivate* retPrivData = new V8DOMImplementation::V8DOMImplementationPrivate();
	retPrivData->dom = privData->dom;
	retPrivData->nativeObj = arbaicaRet;

	arbaicaRetObj->SetInternalField(0, V8DOM::toExternal(retPrivData));
	arbaicaRetObj.MakeWeak(0, V8DOMImplementation::jsDestructor);
	return arbaicaRetObj;

}

v8::Handle<v8::Value> V8Document::documentElementAttrGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
	v8::Local<v8::Object> self = info.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));

	if (!privData->nativeObj->getDocumentElement()) return v8::Undefined();
	Arabica::DOM::Element<std::string>* arbaicaRet = new Arabica::DOM::Element<std::string>(privData->nativeObj->getDocumentElement());

	v8::Handle<v8::Function> arbaicaRetCtor = V8Element::getTmpl()->GetFunction();
	v8::Persistent<v8::Object> arbaicaRetObj = v8::Persistent<v8::Object>::New(arbaicaRetCtor->NewInstance());

	struct V8Element::V8ElementPrivate* retPrivData = new V8Element::V8ElementPrivate();
	retPrivData->dom = privData->dom;
	retPrivData->nativeObj = arbaicaRet;

	arbaicaRetObj->SetInternalField(0, V8DOM::toExternal(retPrivData));
	arbaicaRetObj.MakeWeak(0, V8Element::jsDestructor);
	return arbaicaRetObj;

}

v8::Handle<v8::Value> V8Document::createElementCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localTagName(args[0]);

		Arabica::DOM::Element<std::string>* retVal = new Arabica::DOM::Element<std::string>(privData->nativeObj->createElement(*localTagName));
		v8::Handle<v8::Function> retCtor = V8Element::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Element::V8ElementPrivate* retPrivData = new V8Element::V8ElementPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Element::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createElement");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createDocumentFragmentCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 0) {

		Arabica::DOM::DocumentFragment<std::string>* retVal = new Arabica::DOM::DocumentFragment<std::string>(privData->nativeObj->createDocumentFragment());
		v8::Handle<v8::Function> retCtor = V8DocumentFragment::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8DocumentFragment::V8DocumentFragmentPrivate* retPrivData = new V8DocumentFragment::V8DocumentFragmentPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8DocumentFragment::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createDocumentFragment");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createTextNodeCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localData(args[0]);

		Arabica::DOM::Text<std::string>* retVal = new Arabica::DOM::Text<std::string>(privData->nativeObj->createTextNode(*localData));
		v8::Handle<v8::Function> retCtor = V8Text::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Text::V8TextPrivate* retPrivData = new V8Text::V8TextPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Text::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createTextNode");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createCommentCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localData(args[0]);

		Arabica::DOM::Comment<std::string>* retVal = new Arabica::DOM::Comment<std::string>(privData->nativeObj->createComment(*localData));
		v8::Handle<v8::Function> retCtor = V8Comment::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Comment::V8CommentPrivate* retPrivData = new V8Comment::V8CommentPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Comment::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createComment");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createCDATASectionCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localData(args[0]);

		Arabica::DOM::CDATASection<std::string>* retVal = new Arabica::DOM::CDATASection<std::string>(privData->nativeObj->createCDATASection(*localData));
		v8::Handle<v8::Function> retCtor = V8CDATASection::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8CDATASection::V8CDATASectionPrivate* retPrivData = new V8CDATASection::V8CDATASectionPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8CDATASection::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createCDATASection");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createProcessingInstructionCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsString() &&
	           args[1]->IsString()) {
		v8::String::AsciiValue localTarget(args[0]);
		v8::String::AsciiValue localData(args[1]);

		Arabica::DOM::ProcessingInstruction<std::string>* retVal = new Arabica::DOM::ProcessingInstruction<std::string>(privData->nativeObj->createProcessingInstruction(*localTarget, *localData));
		v8::Handle<v8::Function> retCtor = V8ProcessingInstruction::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8ProcessingInstruction::V8ProcessingInstructionPrivate* retPrivData = new V8ProcessingInstruction::V8ProcessingInstructionPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8ProcessingInstruction::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createProcessingInstruction");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createAttributeCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localName(args[0]);

		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->createAttribute(*localName));
		v8::Handle<v8::Function> retCtor = V8Attr::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Attr::V8AttrPrivate* retPrivData = new V8Attr::V8AttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Attr::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createAttribute");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createEntityReferenceCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localName(args[0]);

		Arabica::DOM::EntityReference<std::string>* retVal = new Arabica::DOM::EntityReference<std::string>(privData->nativeObj->createEntityReference(*localName));
		v8::Handle<v8::Function> retCtor = V8EntityReference::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8EntityReference::V8EntityReferencePrivate* retPrivData = new V8EntityReference::V8EntityReferencePrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8EntityReference::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createEntityReference");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::getElementsByTagNameCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localTagname(args[0]);

		Arabica::DOM::NodeList<std::string>* retVal = new Arabica::DOM::NodeList<std::string>(privData->nativeObj->getElementsByTagName(*localTagname));
		v8::Handle<v8::Function> retCtor = V8NodeList::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8NodeList::V8NodeListPrivate* retPrivData = new V8NodeList::V8NodeListPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8NodeList::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling getElementsByTagName");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::importNodeCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsObject() && V8Node::hasInstance(args[0]) &&
	           args[1]->IsBoolean()) {
		Arabica::DOM::Node<std::string>* localImportedNode = V8DOM::toClassPtr<V8Node::V8NodePrivate >(args[0]->ToObject()->GetInternalField(0))->nativeObj;
		bool localDeep = args[1]->ToBoolean()->BooleanValue();

		Arabica::DOM::Node<std::string>* retVal = new Arabica::DOM::Node<std::string>(privData->nativeObj->importNode(*localImportedNode, localDeep));
		v8::Handle<v8::Function> retCtor = V8Node::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Node::V8NodePrivate* retPrivData = new V8Node::V8NodePrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Node::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling importNode");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createElementNSCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsString() &&
	           args[1]->IsString()) {
		v8::String::AsciiValue localNamespaceURI(args[0]);
		v8::String::AsciiValue localQualifiedName(args[1]);

		Arabica::DOM::Element<std::string>* retVal = new Arabica::DOM::Element<std::string>(privData->nativeObj->createElementNS(*localNamespaceURI, *localQualifiedName));
		v8::Handle<v8::Function> retCtor = V8Element::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Element::V8ElementPrivate* retPrivData = new V8Element::V8ElementPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Element::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createElementNS");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::createAttributeNSCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsString() &&
	           args[1]->IsString()) {
		v8::String::AsciiValue localNamespaceURI(args[0]);
		v8::String::AsciiValue localQualifiedName(args[1]);

		Arabica::DOM::Attr<std::string>* retVal = new Arabica::DOM::Attr<std::string>(privData->nativeObj->createAttributeNS(*localNamespaceURI, *localQualifiedName));
		v8::Handle<v8::Function> retCtor = V8Attr::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Attr::V8AttrPrivate* retPrivData = new V8Attr::V8AttrPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Attr::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling createAttributeNS");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::getElementsByTagNameNSCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsString() &&
	           args[1]->IsString()) {
		v8::String::AsciiValue localNamespaceURI(args[0]);
		v8::String::AsciiValue localLocalName(args[1]);

		Arabica::DOM::NodeList<std::string>* retVal = new Arabica::DOM::NodeList<std::string>(privData->nativeObj->getElementsByTagNameNS(*localNamespaceURI, *localLocalName));
		v8::Handle<v8::Function> retCtor = V8NodeList::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8NodeList::V8NodeListPrivate* retPrivData = new V8NodeList::V8NodeListPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8NodeList::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling getElementsByTagNameNS");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8Document::getElementByIdCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8DocumentPrivate* privData = V8DOM::toClassPtr<V8DocumentPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsString()) {
		v8::String::AsciiValue localElementId(args[0]);

		Arabica::DOM::Element<std::string>* retVal = new Arabica::DOM::Element<std::string>(privData->nativeObj->getElementById(*localElementId));
		v8::Handle<v8::Function> retCtor = V8Element::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8Element::V8ElementPrivate* retPrivData = new V8Element::V8ElementPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8Element::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling getElementById");
	return v8::Undefined();
}
bool V8Document::hasInstance(v8::Handle<v8::Value> value) {
	return getTmpl()->HasInstance(value);
}

}
}
