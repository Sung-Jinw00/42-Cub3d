/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:17:35 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/22 17:18:15 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_read_file(char *file_name);

#endif