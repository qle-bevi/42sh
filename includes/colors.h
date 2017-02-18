/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:14:29 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 20:14:30 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/*
**		DEFINE CONTROL SEQUENCES FOR FORMATTING TEXT
*/

# define INIT			"\e[0m"
# define BOLD			"\e[1m"
# define DIM			"\e[2m"
# define UNDERLINED		"\e[4m"
# define BLINK			"\e[5m"
# define REVERSE		"\e[7m"
# define HIDDEN			"\e[8m"

/*
**		THE FOLLOWING COLORS WORKS WITH ITERM2 AND MOST TERMINALS
**		NOTE: THE COLORS CAN VARY DEPENDING OF THE TERMINAL CONFIGURATION
*/

/*
**		Regular Colors
*/

# define BLACK			"\e[0;30m"
# define RED			"\e[0;31m"
# define GREEN			"\e[0;32m"
# define YELLOW			"\e[0;33m"
# define BLUE			"\e[0;34m"
# define PURPLE			"\e[0;35m"
# define CYAN			"\e[0;36m"
# define WHITE			"\e[0;37m"

/*
**		Bold Style
*/

# define B_BLACK		"\e[1;30m"
# define B_RED			"\e[1;31m"
# define B_GREEN		"\e[1;32m"
# define B_YELLOW		"\e[1;33m"
# define B_BLUE			"\e[1;34m"
# define B_PURPLE		"\e[1;35m"
# define B_CYAN			"\e[1;36m"
# define B_WHITE		"\e[1;37m"

/*
**		Bold High Intensty Colors
*/

# define H_BLACK		"\e[1;90m"
# define H_RED			"\e[1;91m"
# define H_GREEN		"\e[1;92m"
# define H_YELLOW		"\e[1;93m"
# define H_BLUE			"\e[1;94m"
# define H_PURPLE		"\e[1;95m"
# define H_CYAN			"\e[1;96m"
# define H_WHITE		"\e[1;97m"

/*
**		Background Colors
*/

# define BK_BLACK		"\e[40m"
# define BK_RED			"\e[41m"
# define BK_GREEN		"\e[42m"
# define BK_YELLOW		"\e[43m"
# define BK_BLUE		"\e[44m"
# define BK_PURPLE		"\e[45m"
# define BK_CYAN		"\e[46m"
# define BK_WHITE		"\e[47m"

/*
**		High Intensty Backgrounds
*/

# define BKI_BLACK		"\e[100m"
# define BKI_RED		"\e[101m"
# define BKI_GREEN		"\e[102m"
# define BKI_YELLOW		"\e[103m"
# define BKI_BLUE		"\e[104m"
# define BKI_PURPLE		"\e[105m"
# define BKI_CYAN		"\e[106m"
# define BKI_WHITE		"\e[107m"

#endif
