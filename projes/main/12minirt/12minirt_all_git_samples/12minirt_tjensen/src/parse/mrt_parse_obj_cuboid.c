/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_obj_cuboid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:56:42 by tjensen           #+#    #+#             */
/*   Updated: 2022/06/10 09:33:23 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt_parse.h"
#include "print/mrt_print.h"

static int	obj_cuboid_sides(t_list **l_obj, t_vec3 size, t_obj *c_templ);
static int	obj_cuboid_sides_x(t_list **l_obj, t_vec3 size, t_obj *c_templ);
static int	obj_cuboid_sides_y(t_list **l_obj, t_vec3 size, t_obj *c_templ);
static int	obj_cuboid_sides_z(t_list **l_obj, t_vec3 size, t_obj *c_templ);

int	parse_obj_cuboid(t_scene *scene, char **split, int line_num)
{
	t_list	*obj;
	t_vec3	size;

	if (ft_split_count_str(split) != 10)
		return (print_error_scene(line_num, ERR_PARSE, ERR_NUM_PARA, NULL));
	obj = obj_new();
	if (obj == NULL)
		return (print_error_scene(line_num, ERR_PARSE, strerror(errno), NULL));
	ft_lstadd_back(&(scene->l_obj), obj);
	if (parse_vec3(split[1], &(obj_cont(obj)->rt.pos)))
		return (print_error_scene(line_num, ERR_PARSE, ERR_POS, VEC3_RANGE));
	if (double_from_str(split[2], 6, 4, &size.x) || size.x <= 0.0)
		return (print_error_scene(line_num, ERR_PARSE, ERR_WIDTH, NULL));
	if (double_from_str(split[3], 6, 4, &size.y) || size.y <= 0.0)
		return (print_error_scene(line_num, ERR_PARSE, ERR_HEIGHT, NULL));
	if (double_from_str(split[4], 6, 4, &size.z) || size.z <= 0.0)
		return (print_error_scene(line_num, ERR_PARSE, ERR_DEPTH, NULL));
	if (parse_vec3(split[5], &(obj_cont(obj)->rt.rot)))
		return (print_error_scene(line_num, ERR_PARSE, ERR_ROT, VEC3_RANGE));
	if (parse_material(&(obj_cont(obj)->material), &split[6], line_num))
		return (-1);
	if (obj_cuboid_sides(&(scene->l_obj), size, obj_cont(obj)))
		return (-1);
	return (0);
}

static int	obj_cuboid_sides(t_list **l_obj, t_vec3 size, t_obj *c_templ)
{
	t_obj	*c_obj;

	c_templ->print = &print_obj_rectangle;
	c_templ->normal = &normal_rectangle;
	c_obj = c_templ;
	c_obj->rt.dir = (t_vec3){0.0, 0.0, 1.0};
	c_obj->rt.width = size.x;
	c_obj->rt.height = size.y;
	c_obj->rt.rel_pos = (t_vec3){0.0, 0.0, size.z / 2.0};
	c_obj->intersect = parse_obj_rt_intersect(c_obj->rt.dir);
	if (obj_cuboid_sides_z(l_obj, size, c_templ))
		return (-1);
	if (obj_cuboid_sides_y(l_obj, size, c_templ))
		return (-1);
	if (obj_cuboid_sides_x(l_obj, size, c_templ))
		return (-1);
	return (0);
}

static int	obj_cuboid_sides_z(t_list **l_obj, t_vec3 size, t_obj *c_templ)
{
	t_list	*obj;
	t_obj	*c_obj;

	obj = obj_new();
	if (obj == NULL)
		return (print_error_scene(-1, ERR_PARSE, strerror(errno), NULL));
	ft_lstadd_back(l_obj, obj);
	c_obj = obj_cont(obj);
	*c_obj = *c_templ;
	c_obj->rt.dir = (t_vec3){0.0, 0.0, -1.0};
	c_obj->rt.width = size.x;
	c_obj->rt.height = size.y;
	c_obj->rt.rel_pos = (t_vec3){0.0, 0.0, size.z / -2.0};
	c_obj->intersect = parse_obj_rt_intersect(c_obj->rt.dir);
	return (0);
}

static int	obj_cuboid_sides_y(t_list **l_obj, t_vec3 size, t_obj *c_templ)
{
	t_list	*obj_plus;
	t_list	*obj_minus;
	t_obj	*c_obj;

	obj_plus = obj_new();
	if (obj_plus == NULL)
		return (print_error_scene(-1, ERR_PARSE, strerror(errno), NULL));
	ft_lstadd_back(l_obj, obj_plus);
	c_obj = obj_cont(obj_plus);
	*c_obj = *c_templ;
	c_obj->rt.dir = (t_vec3){0.0, 1.0, 0.0};
	c_obj->rt.width = size.x;
	c_obj->rt.height = size.z;
	c_obj->rt.rel_pos = (t_vec3){0.0, size.y / 2.0, 0.0};
	c_obj->intersect = parse_obj_rt_intersect(c_obj->rt.dir);
	obj_minus = obj_new();
	if (obj_minus == NULL)
		return (print_error_scene(-1, ERR_PARSE, strerror(errno), NULL));
	ft_lstadd_back(l_obj, obj_minus);
	c_obj = obj_cont(obj_minus);
	*c_obj = *obj_cont(obj_plus);
	c_obj->rt.dir = (t_vec3){0.0, -1.0, 0.0};
	c_obj->rt.rel_pos = (t_vec3){0.0, size.y / -2.0, 0.0};
	return (0);
}

static int	obj_cuboid_sides_x(t_list **l_obj, t_vec3 size, t_obj *c_templ)
{
	t_list	*obj_plus;
	t_list	*obj_minus;
	t_obj	*c_obj;

	obj_plus = obj_new();
	if (obj_plus == NULL)
		return (print_error_scene(-1, ERR_PARSE, strerror(errno), NULL));
	ft_lstadd_back(l_obj, obj_plus);
	c_obj = obj_cont(obj_plus);
	*c_obj = *c_templ;
	c_obj->rt.dir = (t_vec3){1.0, 0.0, 0.0};
	c_obj->rt.width = size.z;
	c_obj->rt.height = size.y;
	c_obj->rt.rel_pos = (t_vec3){size.x / 2.0, 0.0, 0.0};
	c_obj->intersect = parse_obj_rt_intersect(c_obj->rt.dir);
	obj_minus = obj_new();
	if (obj_minus == NULL)
		return (print_error_scene(-1, ERR_PARSE, strerror(errno), NULL));
	ft_lstadd_back(l_obj, obj_minus);
	c_obj = obj_cont(obj_minus);
	*c_obj = *obj_cont(obj_plus);
	c_obj->rt.dir = (t_vec3){-1.0, 0.0, 0.0};
	c_obj->rt.rel_pos = (t_vec3){size.x / -2.0, 0.0, 0.0};
	return (0);
}
