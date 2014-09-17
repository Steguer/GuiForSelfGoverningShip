#ifndef PARSSER_H
#define PARSSER_H

#include <iostream>
#include <string>
#include <json/json.h>
#include <fstream>

using namespace std;

class Parsser
{
private:
	static string m_filePath;
public:
	Parsser();
	~Parsser();

	static Json::Value readConfigFile()
	{
		Json::Value root;
		Json::Reader reader;

		//Opening of the config file.
		ifstream inFile(m_filePath);
		std::cout<<m_filePath<<std::endl;

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

		return root;
	}

	static Json::Value readConfig(string const& id)
	{
		return Parsser::readConfigFile()[id];
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

	static double readConfigDouble(string const& id)
	{
		return (Parsser::readConfig(id)).asDouble();
	}

	template <typename T>
	static void writeConfig(string const& id, T const& data)
	{
		Json::Value root;
		Json::Reader reader;
		Json::StyledStreamWriter writer;

		//Opening of the config file.
		ifstream inFile(m_filePath);

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
				ofstream outFile(m_filePath);
	    		if(outFile)
	    		{
	    			root[id] = data;
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

	static string getFilePath();
	static void setFilePath(string const& newFilePath);
};

#endif