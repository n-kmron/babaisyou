#ifndef LEVEL_H
#define LEVEL_H

/**
 * @brief The Level class
 *
 * note that we did an inline class because of the small size
 */
class Level
{
    private:
        int height_;
        int width_;
        int numLevel_;

    public:

        inline Level(const int & height, const int & width, const int & numLevel);

        /**
         * @brief default size of our 5 levels is 18x18
         */
        inline Level(const int & numLevel);

        //getters
        inline int height() const;
        inline int width() const;
        inline int numLevel() const;
};

Level::Level(const int & height, const int & width, const int & numLevel) : height_ { height }, width_ { width }, numLevel_ { numLevel } {
}

Level::Level(const int & numLevel) : height_ { 18 }, width_ { 18 }, numLevel_ { numLevel } {
}

int Level::height() const {
    return height_;
}

int Level::width() const {
    return width_;
}

int Level::numLevel() const {
    return numLevel_;
}

#endif // LEVEL_H
