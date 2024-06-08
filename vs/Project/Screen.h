#ifndef SCREEN_H
#define SCREEN_H

namespace Engine {
    class Game; // Forward declaration to avoid circular dependency

    class Screen {
    public:
        virtual ~Screen() {}
        virtual void Init(Game* game) = 0;
        virtual void Update(Game* game) = 0;
        virtual void Render(Game* game) = 0;
    };
}

#endif
