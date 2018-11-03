#include "network.h"
#include <algorithm>
#include <iostream>
#include "random.h"

void Network::resize(const size_t& a)
{
	
	RandomNumbers rng;
	if(not(values.empty()))
	{
		values.clear();	
	}
	values.resize(a);
	rng.normal(values);
}

bool Network::add_link(const size_t& a, const size_t& b)
{
if(not(values.empty()) and a!=b)
	{
		const size_t x(values.size());
		for(unsigned int i(0);i<x;i++)
		{
			if(i ==a)
			{
				for(unsigned int j(0);j<x;j++)
					{
						if((j == b))
							{
								links.insert({a,b});
								links.insert({b,a});
								return true;
							}
							
					}
			}
		}
	}

return false;

}
	

size_t Network::random_connect(const double& mean_deg)
{
	if(not(links.empty()))
	{
		links.clear();
	}
	if(not(values.empty()))
	{
		for(unsigned int i(0);i<values.size();i++)
		{
			RandomNumbers b;
			size_t a(b.poisson(mean_deg) % values.size());
			add_link(a,i);
		}
		return links.size();
	}
	std::cout<<"Le tableau de valeur est vide"<<std::endl;
	return links.size();

	
	
}

size_t Network::set_values(const std::vector<double>& a) 
{
	if(not(a.empty()))
	{
		const size_t  x(values.size()),y(a.size());
		if(x>y)
		{
			for(unsigned int i(0);i<y;i++)
			{
				values[i] = a[i];
			}
			return a.size();
		}
		if(x<y)
		{
			for(unsigned int i(0);i<x;i++)
			{
				values[i] = a[i];
			}
			return a.size();
		}
		if(x == y)
		{
			values = a;
			return a.size();
		}
		
	}
	
	std::cout<<"Votre tableau est vide"<<std::endl;
	return 0;
}


size_t Network::size() const
{
	if(not(values.empty()))
	{
		return values.size();
	}
	std::cout<<"Le tableau est vide"<<std::endl;
	return 0;
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
	if(not(values.empty()))
	{
		std::vector<double> copie_value(values);
		std::sort(copie_value.begin(),copie_value.end());
		std::reverse(copie_value.begin(),copie_value.end());
		return copie_value;
	}
	std::cout<<"le tableau est vide"<<std::endl;
	return values;
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
			if(x.second == a)
			{
				voisin.push_back(x.first);
			}
		}
		for(unsigned int i(0);i<voisin.size();i++)
		{
			for(unsigned int j(i+1);j<voisin.size();j++)
			{
				if(voisin[i] == voisin[j])
				{
					voisin.erase(voisin.begin()+j);
					
				}
			}
		}
		std::reverse(voisin.begin(),voisin.end());
		return voisin;
	}
	std::cout<<"Le tableau est vide"<<std::endl;
	return voisin;
}
