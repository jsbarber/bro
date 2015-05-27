
#include "Foo.h"

using namespace plugin::Demo_Foo;

Foo::Foo()
	{
	}

pktpost::PktPost* Foo::Instantiate()
	{
	return new Foo();
	}

Foo::~Foo()
	{
	}

void Foo::Initialize()
	{
	}

void Foo::Finalize()
	{
	}

void Foo::Process(const Packet *pkt)
	{
	printf("%lu.%06lu %02x:%02x:%02x:%02x:%02x:%02x => %02x:%02x:%02x:%02x:%02x:%02x (%u / %x)\n",
		pkt->ts.tv_sec, pkt->ts.tv_usec,
		pkt->data[6], pkt->data[7], pkt->data[8], pkt->data[9], pkt->data[10], pkt->data[11],
		pkt->data[0], pkt->data[1], pkt->data[2], pkt->data[3], pkt->data[4], pkt->data[5],
		pkt->len, pkt->eth_type);
	}
