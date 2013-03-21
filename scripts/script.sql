CREATE TABLE IF NOT EXISTS card_list (
		internal_id NUMBER PRIMARY KEY ON CONFLICT FAIL,
		card_name TEXT UNIQUE ON CONFLICT REPLACE,
		mana_cost TEXT,
		converted_mana_cost NUMBER,
		color NUMBER,
		power NUMBER,
		toughness NUMBER
		quantity NUMBER
--		tags, --TODO
--		notes --TODO
	)
;

INSERT INTO card_list (card_name, mana_cost, power, toughness) VALUES
	("Slitherhead", "[bg]", 1, 1),
	("Lotleth Troll", "bg", 2, 1),
	("Jarad's Orders", "2bg", 0, 0),
	("Ethereal Armor", "w", 0, 0)
;

SELECT internal_id, card_name FROM card_list;
