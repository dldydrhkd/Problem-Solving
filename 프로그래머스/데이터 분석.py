def solution(data, ext, val_ext, sort_by):
    col_map = {"code":0, "date":1, "maximum":2, "remain":3}
    new_data = []
    for d in data:
        if d[col_map[ext]] < val_ext:
            new_data.append(d)
    
    new_data.sort(key = lambda x : x[col_map[sort_by]])
    return new_data
