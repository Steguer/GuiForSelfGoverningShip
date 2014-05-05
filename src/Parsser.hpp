#ifndef PARSSER_H
#define PARSSER_H

#include <iostream>
#include <string>
#include <json/json.h>
#include <fstream>

using namespace std;

class Parsser
{
public:
	Parsser();
	~Parsser();

	static Json::Value readConfig(string const& id)
	{
		Json::Value root;
		Json::Reader reader;

		//Opening of the config file.
		ifstream inFile("../../rsc/config.json");

		if(inFile)
		{
			bool parsingSuccessful = reader.parse(inFile, root);
			if ( !parsingSuccessful )
			{
			    // report to the user the failure and their locations in the document.
			    std::cout  << "Failed to parse configuration\n"<<endl;
			}

			// cout<<root[id].asInt()<<endl;
		}
		else
		{
		    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		}

		return root[id];
	}
	
	static int readConfigInt(string const& id)
	{
		return (Parsser::readConfig(id)).asInt();
	}

	static string readConfigStr(string const& id)
	{
		return (Parsser::readConfig(id)).asString();
	}

	static bool readConfigBool(string const& id)
	{
		return (Parsser::readConfig(id)).asBool();
	}

	template <typename T>
	static void writeConfig(string const& id, T const& data)
	{
		Json::Value root;
		Json::Reader reader;
		Json::StyledStreamWriter writer;

		//Opening of the config file.
		ifstream inFile("../../rsc/config.json");

		if(inFile)
		{
			bool parsingSuccessful = reader.parse(inFile, root);
			if ( !parsingSuccessful )
			{
			    // report to the user the failure and their locations in the document.
			    std::cout  << "Failed to parse configuration\n"<<endl;
			}
			else
			{
				ofstream outFile("../../rsc/config.json");
	    		if(outFile)
	    		{
	    			root[id] = data.toStdString();
					writer.write(outFile, root);
	    		}
	    		else
	    		{
	    			cout << "ERREUR: Impossible d'ouvrir le fichier en écriture." << endl;
	    		}
			}

			// cout<<root[id].asInt()<<endl;
		}
		else
		{
		    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
		}

	}
};

#endif