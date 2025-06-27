#pragma once
#include <QAbstractListModel>
#include "Ability.h"
#include <vector>

class AbilityModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum AbilityRoles { NameRole = Qt::UserRole + 1, DescriptionRole, LevelRole };

    AbilityModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addAbility(const Ability& ability);
    void removeAbility(int row);
    Ability getAbility(int row) const;

private:
    std::vector<Ability> m_abilities;
}; 