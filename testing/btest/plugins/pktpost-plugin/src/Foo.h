
#ifndef BRO_PLUGIN_DEMO_FOO_H
#define BRO_PLUGIN_DEMO_FOO_H

#include <pktpost/PktPost.h>

namespace plugin {
namespace Demo_Foo {

class Foo : public pktpost::PktPost {
public:
	Foo();
	virtual ~Foo();

	static PktPost* Instantiate();

	virtual void Initialize();
	virtual void Finalize();
	virtual void Process(const Packet *pkt);
};

}
}

#endif
