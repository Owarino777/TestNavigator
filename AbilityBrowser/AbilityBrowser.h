#pragma once
#include <QWidget>
#include "AbilityModel.h"

class AbilityBrowser : public QWidget {
    Q_OBJECT

public:
    AbilityBrowser(QWidget* parent = nullptr);
    ~AbilityBrowser();

private slots:
    void onAddAbility();
    void onRemoveAbility();

private:
    AbilityModel* m_model;
    QListView* m_listView;
    QPushButton* m_addButton;
    QPushButton* m_removeButton;
    QLabel* m_label;
    void setupUi();
    void setupConnections();
}; 