#pragma once
#include <QString>

class Ability {
public:
    Ability(const QString& name, const QString& description, int level);

    QString name() const;
    QString description() const;
    int level() const;

    void setName(const QString& name);
    void setDescription(const QString& description);
    void setLevel(int level);

private:
    QString m_name;
    QString m_description;
    int m_level;
}; 