// Flashlight class declaration.
class Flashlight
{
   private:
      double voltage;
      double resistance;
      bool state;
   public:
      Flashlight(double, double, bool);
      void setVolt(double);
      void setResis(double);
      void setMove(bool);
      double getVolt() const;
      double getRes() const;
      bool getState() const;
      double getCurrent() const;
      double getPower() const;
};