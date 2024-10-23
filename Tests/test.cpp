#include "pch.h"
#include "MockShape.h"
#include "MockPainter.h"
#include "MockCanvas.h"
#include "MockDesigner.h"
#include "MockShapeFactory.h"
#include "../Factory/Client/Client.h"
#include "../Factory/Designer/Designer.h"
#include "../Factory/Painter/Painter.h"

TEST(TestMain, OrderPicture)
{
	MockDesigner mockDesigner;
	MockPainter mockPainter;
	MockCanvas mockCanvas;
	Client client(mockDesigner);

	EXPECT_CALL(mockDesigner, CreateDraft(testing::_)).Times(1);
	EXPECT_CALL(mockPainter, DrawPicture(testing::_, testing::_)).Times(1);

	std::istringstream descr("descr");
	client.OrderPictureByDescription(descr, mockPainter, mockCanvas);
}

TEST(TestMain, DraftShapes)
{
	MockShapeFactory mockFactory;
	Designer designer(mockFactory);

	EXPECT_CALL(mockFactory, CreateShape("Triangle"))
		.WillOnce(testing::Return(testing::ByMove(std::make_unique<MockShape>(Color::Pink))));
	EXPECT_CALL(mockFactory, CreateShape("Rectangle"))
		.WillOnce(testing::Return(testing::ByMove(std::make_unique<MockShape>(Color::Black))));

	std::istringstream dsecr("Triangle\nRectangle");
	PictureDraft draft = designer.CreateDraft(dsecr);

	EXPECT_EQ(draft.GetShapeCount(), 2);
	EXPECT_EQ(draft.GetShape(0).GetColor(), Color::Pink);
	EXPECT_EQ(draft.GetShape(1).GetColor(), Color::Black);
}

TEST(TestMain, DrawShapesOrder)
{
	MockCanvas canvas;
	PictureDraft draft;

	auto shape1 = std::make_unique<MockShape>(Color::Pink);
	auto shape2 = std::make_unique<MockShape>(Color::Black);

	MockShape* shapePtr1 = shape1.get();
	MockShape* shapePtr2 = shape2.get();

	draft.AddShape(std::move(shape1));
	draft.AddShape(std::move(shape2));

	Painter painter;

	EXPECT_CALL(*shapePtr1, Draw(::testing::Ref(canvas))).Times(1);
	EXPECT_CALL(*shapePtr2, Draw(::testing::Ref(canvas))).Times(1);

	painter.DrawPicture(draft, canvas);
}