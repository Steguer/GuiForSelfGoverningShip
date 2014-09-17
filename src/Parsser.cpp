#include "Parsser.hpp"

string Parsser::m_filePath = "";

Parsser::Parsser()
{

}

Parsser::~Parsser()
{

}

string Parsser::getFilePath()
{
	return m_filePath;
}

void Parsser::setFilePath(string const& newFilePath)
{
	if(m_filePath != newFilePath)
	{
		m_filePath = newFilePath;
	}
}
