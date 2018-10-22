#include "network.h"
#include <algorithm>
void Network::resize(const size_t& a)
{
	values.resize(a);
}

bool Network::add_link(const size_t& a, const size_t& b)
{
	for(auto x : links)
	{
		if((x.first == a and x.second == b) or (x.first == b and x.second == b))
		{
			links.insert({a,b});
			return true;
		}
	}
	return false;
}
	

size_t Network::random_connect(const double& a)
{
	
}

size_t Network::set_values(const std::vector<double>& a) 
{
	
}

size_t Network::size() const
{
	return links.size();
}

size_t Network::degree(const size_t& n) const
{
	return links.count(n);
	
}

double Network::value(const size_t& n) const
{
	return values[n];
}

std::vector<double> Network::sorted_values() const
{
	std::sort(values.begin(),values.end());
	std::reverse(values.begin(),values.end());
	return values;
}

std::vector<size_t> Network::neighbors(const size_t& a) const
{
	
}
