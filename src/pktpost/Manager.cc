
#include "PktPost.h"
#include "Manager.h"

using namespace pktpost;

void Manager::Init()
{
        const PktPostCompList& post_comps = GetPktPostComps();

	for (PktPostCompList::const_iterator i = post_comps.begin(); i != post_comps.end(); ++i)
		{
		PktPost *post = (*i)->Factory()();
		post->Initialize();
		Add(post);
		}
}

void Manager::Final()
{
	for (PktPostList::iterator i = pkt_posts.begin(); i != pkt_posts.end(); ++i)
		{
		PktPost *post = *i;
		post->Finalize();
		delete post;
		}
	RemoveAll();
}

