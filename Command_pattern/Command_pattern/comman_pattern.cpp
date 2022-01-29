#include "character.h" 
#include "input.h"
#include "unit.h"
using namespace std;

// C++ interface implemented by abstract class
class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Character& actor) = 0; // Pure virtual function
    virtual void execute() = 0; // Pure virtual function
    virtual void undo() = 0; // 撤销(和重做...)
};

class JumpCommand: public Command
{
public:
    virtual void execute(Character& actor) 
    {
        actor.jump(); 
    }
    virtual void execute()
    {
        //nothing
    }
    virtual void undo()
    {
        //nothing
    }
};
JumpCommand jumpInstance; //不太好?

class FireCommand: public Command
{
public:
    virtual void execute(Character& actor) 
    {
        actor.fireGun(); 
    }
    virtual void execute()
    {
        //nothing
    }
    virtual void undo()
    {
        //nothing
    }
};
FireCommand fireInstance; //不太好?

// 移动“unit”
class MoveUnitCommand : public Command
{
public:
    MoveUnitCommand(Unit* unit, int x, int y): unit_(unit), x_(x), y_(y), xBefore_(0), yBefore_(0) {}
    virtual void execute(Character& actor)
    {
        //nothing
    }
    virtual void execute()
    {
        xBefore_ = unit_->x();
        yBefore_ = unit_->y();
        unit_->moveTo(x_, y_);
        cout << "x = " << unit_->x() << " y = " << unit_->y() << endl;
    }
    virtual void undo() // 撤销(和重做...)
    {
        unit_->moveTo(xBefore_, yBefore_);
        cout << "x = " << unit_->x() << " y = " << unit_->y() << endl;
    }
private:
    Unit* unit_;
    int x_, y_;
    int xBefore_, yBefore_;
};

class InputHandler 
{
public:
    InputHandler() { bindCommand(); }

    Command* handleInput();

    // Methods to bind commands
    // TO DO
    //这部分写的不太好
    void bindCommand();
private:
    Command* buttonX_;
    Command* buttonY_;
    //Command* buttonA_;
    //Command* buttonB_;
};

Command* InputHandler::handleInput()
{   
    Unit* unit = getSelectedUnit();

    char ch = getButton();
    // isPressed ?????
    if (isPressed(BUTTON_X, ch)) return buttonX_;
    if (isPressed(BUTTON_Y, ch)) return buttonY_;
    //if (isPressed(BUTTON_A, ch)) return buttonA_;
    //if (isPressed(BUTTON_B, ch)) return buttonB_;

    if (isPressed(BUTTON_W, ch)) {
        int destY = unit->y() + 1;
        return new MoveUnitCommand(unit, unit->x(), destY);
    }
    if (isPressed(BUTTON_S, ch)) {
        int destY = unit->y() - 1;
        return new MoveUnitCommand(unit, unit->x(), destY);
    }
    if (isPressed(BUTTON_A, ch)) {
        int destX = unit->x() - 1;
        return new MoveUnitCommand(unit, destX, unit->y());
    }
    if (isPressed(BUTTON_D, ch)) {
        int destX = unit->x() + 1;
        return new MoveUnitCommand(unit, destX, unit->y());
    }

    // Nothing pressed, do nothing
    return nullptr;
}

//这部分写的不太好
void InputHandler::bindCommand()
{
    buttonX_ = &jumpInstance;
    buttonY_ = &fireInstance;
    //buttonA_ = &jumpInstance; //暂时先这样
    //buttonB_ = &fireInstance; //暂时先这样
}

int main()
{
    Character charactor;
    InputHandler inputHandler;

    Command* command = inputHandler.handleInput();
    if (command)
    {
        //这里还没处理好
        command->execute(charactor);

        command->execute();
        command->undo();
    }

    return 0;
}