#include "AbilityModel.h"

AbilityModel::AbilityModel(QObject* parent) : QAbstractListModel(parent) {}

int AbilityModel::rowCount(const QModelIndex&) const { return static_cast<int>(m_abilities.size()); }

QVariant AbilityModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= static_cast<int>(m_abilities.size()))
        return QVariant();
    const Ability& ability = m_abilities[index.row()];
    switch (role) {
        case NameRole: return ability.name();
        case DescriptionRole: return ability.description();
        case LevelRole: return ability.level();
        default: return QVariant();
    }
}

QHash<int, QByteArray> AbilityModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[DescriptionRole] = "description";
    roles[LevelRole] = "level";
    return roles;
}

void AbilityModel::addAbility(const Ability& ability) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_abilities.push_back(ability);
    endInsertRows();
}

void AbilityModel::removeAbility(int row) {
    if (row < 0 || row >= static_cast<int>(m_abilities.size())) return;
    beginRemoveRows(QModelIndex(), row, row);
    m_abilities.erase(m_abilities.begin() + row);
    endRemoveRows();
}

Ability AbilityModel::getAbility(int row) const {
    if (row < 0 || row >= static_cast<int>(m_abilities.size()))
        return Ability("", "", 0);
    return m_abilities[row];
} 