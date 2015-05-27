#include "Packet.h"

namespace pktpost {

class PktPost {
public:
	/**
	 * Constructor.
	 */
	PktPost() {}

	/**
	 * Destructor.
	 */
	virtual ~PktPost() {}

	/**
	 * Initialize the component.
	 */
	virtual void Initialize() = 0;

	/**
	 * Close up shop.
	 */
	virtual void Finalize() = 0;

	/**
	 * Process a packet.
	 */
	virtual void Process(const Packet *pkt) = 0;
};

}

