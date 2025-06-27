#include "Ability.h"

Ability::Ability(const QString& name, const QString& description, int level)
    : m_name(name), m_description(description), m_level(level) {}

QString Ability::name() const { return m_name; }
QString Ability::description() const { return m_description; }
int Ability::level() const { return m_level; }

void Ability::setName(const QString& name) { m_name = name; }
void Ability::setDescription(const QString& description) { m_description = description; }
void Ability::setLevel(int level) { m_level = level; } 