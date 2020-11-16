#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <string>
#include <map>
#include "component.hpp"
#include "entity_manager.hpp"

class Entity_manager;
class Component;

class Entity {
private:
  Entity_manager& manager;
  bool active;
  std::vector<Component*> components;
  std::map<const std::type_info*, Component*> component_type_map;
public:
  std::string name;
  Entity(Entity_manager& manager);
  Entity(Entity_manager& manager, std::string name);
  void list_all_components();
  void update(float delta_time);
  void render();
  void destroy();
  bool check_if_active() const;

  template <typename T, typename... TArgs>
  T& add_component(TArgs&&... args) {
    T* new_component(new T(std::forward<TArgs>(args)...));
    new_component->owner = this;
    components.emplace_back(new_component);
    component_type_map[&typeid(*new_component)] = new_component;
    new_component->initialize();
    return* new_component;
  }

  template <typename T>
  T* get_component() {
    return static_cast<T*>(component_type_map[&typeid(T)]);
  }

  template <typename T>
  bool has_component() {
    return component_type_map[&typeid(T)];
  }
};

#endif
