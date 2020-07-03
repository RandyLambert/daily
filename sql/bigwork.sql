-- 设计一个采购、销售和客户管理应用数据库，其中：一个供应商可以供应多种零件，一种零件也可以有多个供应商，一个客户订单可以订购多种供应商供应的零件。客户和供应商都分属不同的国家，而国家按世界五大洲四大洋划分地区。请进行数据库设计，要求包含7个实体：零件、供应商、客户、订单、订单项、国家、地区。
-- 每个实体都有一些属性
-- 零件：零件编号，零件名称，制造商，品牌，零售价格，备注
-- 供应商：供应商编号，供应商名称，地址，国籍，电话，备注
-- 客户：客户编号，客户名称，地址，电话，国籍，备注
-- 订单：订单编号，订单状态，，订单总价，订单日期，订单优先级，记账员，备注
-- 订单项：订单项编号，订购零件号，供应商号，零件数量，零件总价，折扣，税率
-- 国家：国家编号，国家名称，所属地区，备注
-- 地区：地区编号，地区名称，备注

-- 第六题,创建表的语句
create table `area`(
	area_id  int unsigned primary key auto_increment,
    area_name  varchar(32),
    remarks varchar(512)
); 

create table country(
	country_id int unsigned primary key auto_increment,
    country_name varchar(32),
    region int unsigned,
    remarks varchar(512),
	CONSTRAINT `fk_countryarea_major` FOREIGN KEY (`region`) REFERENCES `area` (`area_id`)
);

create table customer(
	customer_id int unsigned primary key auto_increment,
    customer_name varchar(32),
    address varchar(128) not null,
    telephone varchar(11) not null  unique key,
    nationality int unsigned,
    remarks varchar(512),
    CONSTRAINT `fk_customercountry_major` FOREIGN KEY (`nationality`) REFERENCES `country` (`country_id`)
);

create table supplier(
	supplier_id int unsigned primary key auto_increment,
	supplier_name varchar(32), 
    address varchar(128) not null,
    nationality int unsigned,
    telephone varchar(11) not null unique key,
    remarks varchar(512),
    CONSTRAINT `fk_suppliercountry_major` FOREIGN KEY (`nationality`) REFERENCES `country` (`country_id`)
);

create table part(
	part_id int unsigned,
    part_name varchar(32),
	manufacturer int unsigned,
    brand varchar(128),
    retail_price double unsigned default 0,
	remarks varchar(512),
    CONSTRAINT `fk_partmanufacturer_major` FOREIGN KEY (`manufacturer`) REFERENCES `supplier` (`supplier_id`),
	primary key (part_id,manufacturer)
);

create table `order`(
	order_id int unsigned primary key auto_increment,
	order_status enum('0','1','2') default '0',
    total_order_price double unsigned default 0,
	order_date datetime not null,
	order_priority tinyint unsigned default 0,
    bookkeeper int unsigned,
    remarks varchar(512),
    CONSTRAINT `fk_orderbookkeeper_major` FOREIGN KEY (`bookkeeper`) REFERENCES `customer` (`customer_id`)
); 


create table order_item(
	order_item_id int unsigned,
    order_part_id int unsigned,
    supplier_id int unsigned,
    part_quantity int unsigned default 1,
    total_part_price double unsigned default 0,
    discount double unsigned default 1,
    tax_rate double unsigned default 1,
    CONSTRAINT `fk_orderitemorder_major` FOREIGN KEY (`order_item_id`) REFERENCES `order` (`order_id`),
    CONSTRAINT `fk_orderitempart_major` FOREIGN KEY (`order_part_id`) REFERENCES `part` (`part_id`),
    CONSTRAINT `fk_orderitemsupplier_major` FOREIGN KEY (`supplier_id`) REFERENCES `supplier` (`supplier_id`),
	primary key(order_item_id,order_part_id,supplier_id)
); 

show tables;
-- 第五题运行这个语句得出的结果 
desc area;
desc country;
desc customer;
desc supplier;
desc part;
desc `order`;
desc order_item;

-- 第七题 
insert into area values(null,"亚洲","test"),(null,"北美洲","test"),(null,"南美洲","test");
insert into country values(null,"china",1,"test"),(null,"japan",1,"test"),(null,"美国",2,"test");

delete from part where part_id = 1;
delete from `order` where order_id = 2;
delete from order_item where order_item_id = 2 AND order_part_id = 1;

update area set area_name = "亚洲" where area_name = "china";
update supplier set supplier_address = "test" where supplier_id = 10;
update customer set customer_name = "test" where customer_id = 5;
 
select * from area group by remarks;
select * from country order by country_name desc;
select * from customer where customer_name Like "%a";
select * from supplier LIMIT 0,1000;
select * from part order by part_id;
select * from `order` inner join order_item on order_item_id = order_id where bookkeeper not in(1,2,3);
select * from order_item;
