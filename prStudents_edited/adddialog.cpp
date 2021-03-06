#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "adddialog.h"
#include "student.h"

AddDialog::AddDialog(QWidget* parent) : QDialog(parent)
{
  nameLineEdit = new QLineEdit;
  yearLineEdit = new QLineEdit;

  QLabel *nameLabel = new QLabel("&Name");
  QLabel *yearLabel = new QLabel("&Year");

  nameLabel->setBuddy(nameLineEdit);
  yearLabel->setBuddy(yearLineEdit);

  QPushButton *okButton = new QPushButton("&Ok");
  QPushButton *cancelButton = new QPushButton("&Cancel");

  connect(okButton, SIGNAL(clicked()), SLOT(accept()));
  connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));

  // Layout setup
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(nameLabel, 0, 0);
  layout->addWidget(yearLabel, 1, 0);
  layout->addWidget(nameLineEdit, 0, 1);
  layout->addWidget(yearLineEdit, 1, 1);
  layout->addWidget(okButton, 2, 0);
  layout->addWidget(cancelButton, 2, 1);
  setLayout(layout);
}

Student AddDialog::student() const
{
    std::string n = nameLineEdit->text().toStdString();
    int y = yearLineEdit->text().toInt();
    return Student(n, y);
}

