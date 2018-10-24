#include "network.h"
#include <algorithm>
#include <iostream>

void Network::resize(const size_t& a)
{
	values.resize(a,a);
}

bool Network::add_link(const size_t& a, const size_t& b)
{
	if(a != b)
	{
		links.insert({a,b});
		return true;
	}
	else
	{	
	return false;
	}
}
	

size_t Network::random_connect(const double& mean_deg)
{
	if(not(links.empty()))
	{
		links.clear();
	}
	if(not(values.empty()))
	{
		for(auto x : values)
		{
			RandomNumbers b;
			size_t a(b.poisson(mean_deg) % values.size());
			add_link(a,x);
			return links.size();
		}
	}
	std::cout<<"Le tableau de valeur est vide"<<std::endl;
	return links.size();

	
	
}

size_t Network::set_values(const std::vector<double>& a) 
{
	if(not(a.empty()))
	{
		values = a;
		return values.size();
	}
	else
	{
		std::cout<<"Votre tableau est vide"<<std::endl;
		return 0;
	}
	
}

size_t Network::size() const
{
	return values.size();
}

size_t Network::degree(const size_t& n) const
{
	if(not(links.empty()))
	{
		return links.count(n);
	}
	std::cout<<"Il n'y a pas de lien"<<std::endl;
	return 0;
	
}

double Network::value(const size_t& n) const
{
	if(not(values.empty()))
	{
		return values[n];
	}
	std::cout<<"le tableau est vide"<<std::endl;
	return 0.0;
}

std::vector<double> Network::sorted_values() const
{
	std::vector<double> copie_value(values);
	std::sort(copie_value.begin(),copie_value.end());
	std::reverse(copie_value.begin(),copie_value.end());
	return copie_value;
}

std::vector<size_t> Network::neighbors(const size_t& a) const
{
	std::vector<size_t> voisin;
	if(not(values.empty()))
	{
		for(auto x : links)
		{
			if((x.first == a))
			{
				voisin.push_back(x.second);
			}
			if((x.second == a))
			{
				voisin.push_back(x.first);
			}
		}
		
		return voisin;
	}
	std::cout<<"Le tableau est vide"<<std::endl;
	return voisin;
}
