#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <vector>
#include "entity.hpp"
#include "component.hpp"

class Entity;

class Entity_manager {
private:
  std::vector<Entity*> entities;
public:
  void clear();
  void update(float delta_time);
  void render();
  bool check_no_entities();
  Entity& add_entity(std::string name);
  std::vector<Entity*> get_entities() const;
  unsigned int get_entity_count() const;
};

#endif