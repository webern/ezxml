// Copyright (c) Matthew James Briggs

#pragma once

#include "ezxml/XElementIterator.h"
#include "ezxml/XElementIterImpl.h"
#include "ezxml/XDoc.h"
#include "private/PugiElement.h"
#include "private/pugixml.hpp"

namespace ezxml
{
    class PugiElementIterImpl : public XElementIterImpl
    {
    public:

        PugiElementIterImpl();

        PugiElementIterImpl(
                const pugi::xml_node_iterator& iter,
                const pugi::xml_node& iterParent,
                const XDocCPtr& parentDoc
        );

        PugiElementIterImpl( const PugiElementIterImpl& ) = default;
        PugiElementIterImpl( PugiElementIterImpl&& ) = default;

        PugiElementIterImpl& operator=( const PugiElementIterImpl& ) = default;
        PugiElementIterImpl& operator=( PugiElementIterImpl&& ) = default;

        virtual bool getIsPayloadNull() const override;
        virtual bool getIsEndIter() const override;
        virtual bool getIsProcessingInstruction() const override;
        virtual bool getSkipProcessingInstructions() const override;
        virtual void setSkipProcessingInstructions( bool inValue ) override;

        virtual XElementIterImplUP clone() const override;
        virtual bool equals( const XElementIterator& other ) const override;

        virtual XElement& getRef() const override;
        virtual XElement* getPtr() const override;

        virtual const PugiElementIterImpl& increment() override;
        virtual const PugiElementIterImpl& decrement() override;

        // not part of inherited interface
        virtual pugi::xml_node_type getPugiXmlNodeType() const final;
        virtual bool hasTextData() const final;

    public:
        pugi::xml_node_iterator myIter;
        pugi::xml_node myIterParent;
        bool mySkipProcessingInstructions;
        XDocCWPtr myXDoc;
        mutable PugiElement myReturnableElement;
    };
}
