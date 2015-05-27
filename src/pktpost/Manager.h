// See the file "COPYING" in the main distribution directory for copyright.

#ifndef PKTPOST_MANAGER_H
#define PKTPOST_MANAGER_H

#include <string>
#include <list>
#include "Component.h"

namespace pktpost {

class PktPost;

/**
 * Singleton class managing all PktPost components.
 */
class Manager {
public:
	/**
	 * Constructor.
	 */
	Manager() { }

	/**
	 * Destructor.
	 */
	virtual ~Manager() { }

	typedef std::list<PktPostComponent *> PktPostCompList;
	typedef std::list<PktPost *> PktPostList;

	/**
	 * Returns a list of all active PktPost instances.
	 */
	const PktPostList& GetPktPosts() const { return pkt_posts; }

	/**
	 * Returns a list of all registered PktPostComponent instances.
	 */
	const PktPostCompList& GetPktPostComps() const { return pkt_post_comps; }

	/**
	 * Register a packet post-processor component.
	 */
	void Register(PktPostComponent *pkt_post_comp)
		{
		pkt_post_comps.push_back(pkt_post_comp);
		}

	/**
	 * Instantiate and initialize each registered post-processor component.
	 */
	void Init();

	/**
	 * Finalize each post-processor, and destroy it.
	 */
	void Final();

private:
	/**
	 * Add an initialized post-processor.
	 */
	void Add(PktPost *pkt_post)
		{
		pkt_posts.push_back(pkt_post);
		}

	/**
	 * Remove all the post-processors from our list.
	 * (They should have already been destroyed.)
	 */
	void RemoveAll()
		{
		pkt_posts.clear();
		}


	PktPostCompList pkt_post_comps;
	PktPostList pkt_posts;
};

}

extern pktpost::Manager* pktpost_mgr;

#endif

