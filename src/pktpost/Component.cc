// See the file "COPYING" in the main distribution directory for copyright.

#include "Manager.h"
#include "Component.h"

using namespace pktpost;

PktPostComponent::PktPostComponent(const std::string& name, factory_callback arg_factory)
	: plugin::Component(plugin::component::PKTPOST, name)
	{
	factory = arg_factory;
	pktpost_mgr->Register(this);
	}

PktPostComponent::~PktPostComponent()
	{
	}

PktPostComponent::factory_callback PktPostComponent::Factory() const
	{
	return factory;
	}

void PktPostComponent::DoDescribe(ODesc* d) const
	{
	plugin::Component::DoDescribe(d);
	}

