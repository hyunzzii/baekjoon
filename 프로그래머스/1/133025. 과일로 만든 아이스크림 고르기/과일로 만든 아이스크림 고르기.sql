-- 코드를 입력하세요
SELECT info.flavor
from icecream_info info, first_half half
where info.flavor=half.flavor and half.total_order>3000 and info.ingredient_type='fruit_based'
order by half.total_order desc
