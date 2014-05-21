#ifndef SENT_TO_WINDOW_HPP
#define SENT_TO_WINDOW_HPP

#include <QtWidgets>
#include <iostream>
#include "Parsser.hpp"

class SendToWindow: public QWidget
{
Q_OBJECT

private:
	QLabel *m_userLabel;
	QLabel *m_ipLabel;
	QLabel *m_pathLabel;
	QLineEdit *m_userEdit;
	QLineEdit *m_ipEdit;
	QLineEdit *m_pathEdit;
	QGridLayout *m_gbox;
	QHBoxLayout *m_hbox;
	QVBoxLayout *m_vbox;
	QPushButton *m_send;
	QPushButton *m_cancel;
	QUrl m_fileTosend;

public slots:
	void sendFile();

public:
	SendToWindow();
	~SendToWindow();

	void showWind(QUrl fileToSend);
	
};

#endif