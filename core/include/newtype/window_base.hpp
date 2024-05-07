#pragma once
#ifndef NEWTYPE_CORE_WINDOW_BASE_HPP
#   define NEWTYPE_CORE_WINDOW_BASE_HPP

namespace newtype
{
    class NT_CORE_API window_base
    {
    public:
        virtual ~window_base() = default;

        /**
         * @brief Opens the window.
         *
         * This pure virtual function defines the behavior of opening the window in derived classes.
         * Depending on the implementation, the function may or may not be used explicitly.
         *
         * @note This function must be implemented in derived classes.
         */
        virtual void open() = 0;

        /**
         * @brief Updates the window events.
         *
         * This pure virtual function updates the window in derived classes.
         *
         * @note This function must be implemented in derived classes.
         */
        virtual void update_events() = 0;

        /**
         * @brief Closes the window.
         *
         * This pure virtual function defines the behavior of closing the window in derived classes.
         * Depending on the implementation, the function may or may not be used explicitly.
         *
         * @note This function must be implemented in derived classes.
         */
        virtual void close() = 0;

        /**
         * @brief Checks if the window is open.
         *
         * This pure virtual function checks whether the window is open in derived classes.
         *
         * @return True if the window is open, false otherwise.
         *
         * @note This function must be implemented in derived classes.
         */
        [[nodiscard]]
        virtual bool is_open() const = 0;

        /**
         * @brief Retrieves the title of the window.
         *
         * This pure virtual function retrieves the title of the window in derived classes.
         *
         * @return The title of the window.
         *
         * @note This function must be implemented in derived classes.
         */
        [[maybe_unused, nodiscard]]
        virtual std::string get_title() const = 0;

        /**
         * @brief Sets the title of the window.
         *
         * This pure virtual function sets the title of the window in derived classes.
         *
         * @param _title The new title to set for the window.
         *
         * @note This function must be implemented in derived classes.
         */
        [[maybe_unused]]
        virtual void set_title(const std::string& _title) = 0;

        /**
         * @brief Retrieves the position of the window.
         *
         * This pure virtual function retrieves the position (coordinates) of the window in derived classes.
         *
         * @return A tuple containing the x and y coordinates of the window's position.
         *
         * @note This function must be implemented in derived classes.
         */
        [[maybe_unused, nodiscard]]
        virtual std::pair<int, int> get_position() const = 0;

        /**
         * @brief Sets the position of the window.
         *
         * This pure virtual function sets the position (coordinates) of the window in derived classes.
         *
         * @param _position A tuple containing the x and y coordinates to set for the window's position.
         *
         * @note This function must be implemented in derived classes.
         */
        [[maybe_unused]]
        virtual void set_position(std::pair<int, int> _position) = 0;

        /**
         * @brief Retrieves the size of the window.
         *
         * This pure virtual function retrieves the size (width and height) of the window in derived classes.
         *
         * @return A tuple containing the width and height of the window's size.
         *
         * @note This function must be implemented in derived classes.
         */
        [[maybe_unused, nodiscard]]
        virtual std::pair<int, int> get_size() const = 0;

        /**
         * @brief Sets the size of the window.
         *
         * This pure virtual function sets the size (width and height) of the window in derived classes.
         *
         * @param _size A tuple containing the width and height to set for the window's size.
         *
         * @note This function must be implemented in derived classes.
         */
        [[maybe_unused]]
        virtual void set_size(std::pair<int, int> _size) = 0;
    };

    /**
     * @brief Creates a new window using the newtype library.
     *
     * This function creates a new window using the newtype library and returns a unique pointer to it.
     * The caller is responsible for managing the memory of the returned window.
     *
     * @return A unique pointer to the created window.
     */
     [[nodiscard]]
    extern std::unique_ptr<newtype::window_base> create_window();
}

#endif //NEWTYPE_CORE_WINDOW_BASE_HPP