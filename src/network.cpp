#include "network.h"
#include <algorithm>
#include <iostream>
#include "random.h"

void Network::resize(const size_t& a)
{
	
	RandomNumbers rng;
	if(not(values.empty()))
	{
		values.clear();				//Programme faisant un remplissage aleatoire.Neanmoins,Probleme avec les tests : Lors d'un premier passage,certain tests passaient et d'autre non.Lors d'un deuxieme passage,l'inverse se produit.Parfois tout les test passent
	}
	values.resize(a);
	for(unsigned int i(0);i<values.size();i++)
	{
		values[i] = (int(rng.normal(i+1)))%a;
	}
	
	
	/*
	if(not(values.empty()))
	{
		values.clear();
	}
	values.resize(a);
	for(unsigned int i(0);i<a;i++)
	{
		values[i] = i;
	}
	*/
}

bool Network::add_link(const size_t& a, const size_t& b)
{
if(not(values.empty()) and a!=b)
	{
		for(unsigned int i(0);i<values.size();i++)
		{
			if((values[i] == b)or(values[i] == b))
			{
				for(unsigned int j(0);j<values.size();j++)
					{
						if(((values[j] == b)or(values[j] == a)))
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
		for(auto x : values)
		{
			RandomNumbers b;
			size_t a(b.poisson(mean_deg) % values.size());
			add_link(a,x);
			
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
