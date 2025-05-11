#include <charconv>     // To `std::from_chars`
#include <cstddef>      // To `std::size_t`
#include <cstdlib>      // To `EXIT_SUCCESS`, `EXIT_FAILURE`
#include <iostream>     // To `std::cout`, `std::cin` `std::getline`
#include <random>       // To `std::mt19937`, `std::random_device`, `std::uniform_int_distribution`
#include <string>       // To `std::string`
#include <thread>       // To `std::this_thread`, `std::chrono`
#include <string_view>  // To `std::string_view`

/// @brief Alias to `std::string`.
using str = std::string;

/// @brief Simple log function.
void log(std::string_view msg = "") { std::cout << msg; }

/// @brief Randomly generates a number between 1 and 6 to represent the bullet's position
short random_bullet()
{
  static std::mt19937 rng(std::random_device{}());  // [!] Pseudo-random number generator.
  std::uniform_int_distribution<> dist(1, 6);       // [!] Uniform distribution between 1 and 6.
  return dist(rng);
}

/// @brief Checks if a string represents a valid number between 1 and 6.
bool is_valid_number(const str& s, short& value)
{
  std::size_t temp{};
  auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), temp);
  if (ec == std::errc() and ptr == s.data() + s.size() and temp >= 1 && temp <= 6)
  {
    value = static_cast<short>(temp);  // [!] Safety conversion to short type.
    return true;
  }
  return false;
}

/// @brief Introduction message presented to the user.
const char* intro_message = R"(Welcome to the Russian Roullete!, v 0.1 (c) 2025

HOW TO PLAY:
  Pick a chamber number (1 to 6) and see if you survive.
  Type "quit" to exit at any time.

)";

/// @brief Suspenseful animation spinning the drum with short delays.
void suspense()
{
  std::cout << "\nTurning the drum";
  for (int i{ 0 }; i < 5; ++i)
  {
    std::cout << ".";
    std::cout.flush();                                            // [!]  Ensures that the point is printed immediately.
    std::this_thread::sleep_for(std::chrono::milliseconds(400));  // [!] Wait 400ms
  }
  std::cout << "\n\n";
}

/// @brief Main function of the game that interacts with the user.
void play_game()
{
  std::cout << intro_message;

  while (true)
  {
    std::cout << "Choose a chamber (1-6) or type \"quit\": ";
    str input{};
    std::getline(std::cin, input);

    if (input == "quit")
    {
      std::cout << "You chickened out... 😅\n";  /// [!] Quit.
      break;
    }

    short user_choice{};
    if (!is_valid_number(input, user_choice))
    {
      std::cout << "Invalid input. Please enter a number from 1 to 6.\n";
      continue;  // [!] Try again...
    }

    short bullet = random_bullet();  // [!] Sorting bullet position.

    std::cout << "You chose chamber " << user_choice << ".\n";
    suspense();

    if (user_choice == bullet)
    {
      std::cout << "💥 BANG! You're dead.\n";
      break;
    }
    std::cout << "😅 *Click*! You survived this round.\n\n";
  }
}

/// @brief Main function that starts the game.
int main()
{
  play_game();
  return EXIT_SUCCESS;
}
