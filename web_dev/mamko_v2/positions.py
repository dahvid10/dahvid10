position_salary = {
    'Legal Developer': 200000,
    'Medical Developer': 200000,
    'Energy Technologist': 250000,
    'Financial Technologist': 250000,
    'Synergist': 150000    
}

position_description = {
    'Legal Developer': 'Legal developers collaborate to advocate for Mamko\'s commercial interests.',
    'Medical Developer': 'Medical developers collaborate to improve healthcare.',
    'Energy Technologist': 'Energy technologists collaborate to create solutions in the energy industry.',
    'Financial Technologist': 'Financial Technologists collaborate to create financial solutions.',
    'Synergist': 'Synergists collaborate to ensure Mamko\'s ecosystem thrives.'    
}

position_scale = {
    1: .65,
    2: .75,
    3: .85,
    4: .95,
    5: 1
}

location_scale = {
    'Houston, TX, USA': .95,
    'Nairobi, Kenya': 0.85,
    'Remote': 0.85
}

positions_list = []
id = 0
for position in position_salary:
    for rank in position_scale:
        for location in location_scale:
            role = {
                'id': id,
                'position': position + ' ' + str(rank),
                'location': location,
                'salary': int(position_salary[position] * position_scale[rank] * location_scale[location]),
                'description': position_description[position]
            }
            positions_list.append(role)
            id += 1