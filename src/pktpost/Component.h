// See the file "COPYING" in the main distribution directory for copyright.

#ifndef PKTPOST_PLUGIN_COMPONENT_H
#define PKTPOST_PLUGIN_COMPONENT_H

#include <string>
#include <vector>

#include "plugin/Component.h"

namespace pktpost {

class PktPost;

/**
 * Component description for plugins providing a packet post-processor.
 *
 */
class PktPostComponent : public plugin::Component  {
public:
	typedef PktPost* (*factory_callback)();

	/**
	 * Constructor.
	 *
	 * @param name A descriptive name for the component.  This name must
	 * be unique across all components of this type.
	 *
	 * @param factor Factory function to instantiate component.
	 */
	PktPostComponent(const std::string& name, factory_callback factory);

	/**
	 * Destructor.
	 */
	~PktPostComponent();

	/**
	 * Returns the source's factory function.
	 */
	factory_callback Factory() const;

	/**
	 * Generates a human-readable description of the component. This goes
	 * into the output of \c "bro -NN".
	 */
	virtual void DoDescribe(ODesc* d) const;

private:
	factory_callback factory;
};

}

#endif
