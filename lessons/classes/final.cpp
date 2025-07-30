/*final keyword prevents overrides by design	*/
class Goblin : public Character {
public:
  void Act() final{} 
};