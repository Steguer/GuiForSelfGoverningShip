#include "PropertiesWindow.hpp"

PropertiesWindow::PropertiesWindow()
{
	m_gbox = new QGridLayout();
	m_cancelButton = new QPushButton("Cancel");
	m_okButton = new QPushButton("Ok");

	auto root = Parsser::readConfigFile();

	vector<string> v = root.getMemberNames();

	for(auto &it : v)
	{
		if(root[it].isInt())
		{
			PropLine tmp_widgetItemVect;
			tmp_widgetItemVect.editText = new QLineEdit(QString::number(Parsser::readConfigInt(it)));
			tmp_widgetItemVect.label = new QLabel( QString(it.c_str()));
			m_widgetItemVect.push_back(tmp_widgetItemVect);
		}
	}

	int i=0;
	for(auto &it : m_widgetItemVect)
	{
		m_gbox->addWidget(it.label, i, 0);
		m_gbox->addWidget(it.editText, i, 1);
		++i;
	}

	m_gbox->addWidget(m_cancelButton, i, 0);
	m_gbox->addWidget(m_okButton, i, 1);

	QObject::connect(m_cancelButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(m_okButton, SIGNAL(clicked()), this, SLOT(save()));

	this->setLayout(m_gbox);
}

PropertiesWindow::~PropertiesWindow()
{

}

void PropertiesWindow::save()
{
	for(auto &it : m_widgetItemVect)
	{
		Parsser::writeConfig((it.label->text()).toStdString(), (it.editText->text()).toInt());
	}

	qApp->quit();
}