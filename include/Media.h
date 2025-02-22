#ifndef _MEDIA_H_
#define _MEDIA_H_
#include <string>

class Media{
private:
    static constexpr const char def_times_consumed = 0;
    static constexpr const char def_user_rating = -1;
protected:
    std::string title;
    int times_consumed;
    int user_rating;
public:
    // Consturtors Movie
    Media(std::string title, int times_consumed=def_times_consumed, int user_rating=def_user_rating);
    bool operator==(const Media &rhs) const;
    bool operator<(const Media &rhs) const;
    bool operator>(const Media &rhs) const;

    // Getters and Setters
    std::string get_title() const;
    int get_times_consumed() const;
    int get_user_rating() const;
    void set_title(std::string title);
    void set_times_consumed(int times_consumed);
    void set_user_rating(int rating);

    // Custom Methods
    void increment_times_consumed(); // Increment number of times consumed
};
#endif //_MEDIA_H_