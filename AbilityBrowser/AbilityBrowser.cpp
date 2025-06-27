#include "AbilityBrowser.h"
#include <QVBoxLayout>
#include <QListView>
#include <QPushButton>
#include <QLabel>
#include <QInputDialog>

AbilityBrowser::AbilityBrowser(QWidget* parent)
    : QWidget(parent), m_model(new AbilityModel(this)) {
    setupUi();
    setupConnections();
}

AbilityBrowser::~AbilityBrowser() {}

void AbilityBrowser::setupUi() {
    auto* layout = new QVBoxLayout(this);

    m_label = new QLabel(tr("Ability Browser"), this);
    m_label->setAccessibleName(tr("Ability Browser Title"));
    layout->addWidget(m_label);

    m_listView = new QListView(this);
    m_listView->setModel(m_model);
    m_listView->setAccessibleName(tr("Ability List"));
    layout->addWidget(m_listView);

    m_addButton = new QPushButton(tr("Add Ability"), this);
    m_addButton->setAccessibleName(tr("Add Ability Button"));
    layout->addWidget(m_addButton);

    m_removeButton = new QPushButton(tr("Remove Ability"), this);
    m_removeButton->setAccessibleName(tr("Remove Ability Button"));
    layout->addWidget(m_removeButton);

    setLayout(layout);
}

void AbilityBrowser::setupConnections() {
    connect(m_addButton, &QPushButton::clicked, this, &AbilityBrowser::onAddAbility);
    connect(m_removeButton, &QPushButton::clicked, this, &AbilityBrowser::onRemoveAbility);
}

void AbilityBrowser::onAddAbility() {
    bool ok;
    QString name = QInputDialog::getText(this, tr("Ability Name"), tr("Enter ability name:"), QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;
    QString desc = QInputDialog::getText(this, tr("Ability Description"), tr("Enter ability description:"), QLineEdit::Normal, "", &ok);
    if (!ok) return;
    int level = QInputDialog::getInt(this, tr("Ability Level"), tr("Enter ability level:"), 1, 1, 100, 1, &ok);
    if (!ok) return;
    m_model->addAbility(Ability(name, desc, level));
}

void AbilityBrowser::onRemoveAbility() {
    QModelIndex index = m_listView->currentIndex();
    if (!index.isValid()) return;
    m_model->removeAbility(index.row());
} 